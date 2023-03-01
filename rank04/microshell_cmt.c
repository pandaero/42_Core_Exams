/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell_cmt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:34:42 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/01 14:36:15 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

//Working file descriptor.
int	temp_fd;

//Function writes to standard error.
int	write_error(char *str)
{
	while (*str != '\0')
		write(STDERR_FILENO, str++, 1);
	return (EXIT_FAILURE);
}

//Function is a built-in directory changer.
int	cd(char **argv, int i)
{
	//Check there are only two (three) arguments.
	if (i != 2)
		return (write_error("error: cd: bad arguments\n"));
	//Make sure the path is openable. Success is 0.
	if (chdir(argv[1]))
	{
		write_error("error: cd: cannot change directory to ");
		write_error(argv[1]);
		return (write_error("\n"));
	}
	return (EXIT_SUCCESS);
}

//Function executes command line starting with i argument.
int	execute(char **argv, char **env, int i)
{
	int	files[2];
	int	pip;
	int	pid;
	int	ret;

	//Whether finishing argument is pipe.
	pip = (argv[i] && !strcmp(argv[i], "|"));

	//If it is a pipe, perform piping with files array. Pipe success 0.
	if (pip && pipe(files))
		return (write_error("error: fatal\n"));
	
	//Create a process for the command line.
	pid = fork();
	//For child (pid = 0).
	if (!pid)
	{
		//Unsure what this does.
		argv[i] = 0;
		//Duplicate STDIN to temp file. Close temp file.
		//If pipe, duplicate STDOUT to WRITE file.
		//(if pipe) Close READ file. Close WRITE file.
		//Any error return fatal message.
		if (dup2(temp_fd, STDIN_FILENO) == -1 | close(temp_fd) == -1 | \
			(pip && (dup2(files[1], STDOUT_FILENO)) == -1 | \
			close(files[0]) == -1 | close(files[1]) == -1))
			return (write_error("error: fatal\n"));
		//Make child a new process. execve only returns on failure.
		execve(*argv, argv, env);
		//Return execution error.
		write_error("error: cannot execute ");
		write_error(*argv);
		return (write_error("\n"));
	}
	//If pipe, duplicate temp file to READ file. Close READ file. Close WRITE.
	//If not pipe, duplicate temp file to STDIN.
	//Any error return fatal message.
	if ((pip && (dup2(files[0], temp_fd) == -1 | close(files[0]) == -1 | \
		close(files[1]) == -1)) | (!pip && dup2(STDIN_FILENO, temp_fd) == -1) \
		| waitpid(pid, &ret, 0) == -1)
		return (write_error("error: fatal\n"));
	//Return exit status.
	return (WIFEXITED(ret) && WEXITSTATUS(ret));
}

//Program is a small command line executor.
int	main(int argc, char **argv, char **env)
{
	int	i;
	int	ret;

	(void) argc;
	//Duplicate STDIN to temp file.
	temp_fd = dup(STDIN_FILENO);

	ret = EXIT_SUCCESS;
	i = 0;
	//If argument element is valid and so is the next one.
	while (argv[i] && argv[++i])
	{
		//Skip to the next argument.
		argv += i;
		//Reset skipping counter.
		i = 0;
		//If argument element is not pipe or semi-colon, count contained args.
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		//If argument calls builtin, perform builtin.
		if (!strcmp(*argv, "cd"))
			ret = cd(argv, i);
		//Pass command that calls plus contained arguments (arg). If i positive.
		else if (i)
			ret = execute(argv, env, i);
	}
	//If can't duplicate STDIN to temp file, print error.
	ret = ((dup2(STDIN_FILENO, temp_fd) == -1) && write_error("error: fatal\n")) | ret;
	return (ret);
}

//Tests
// ./microshell cd .. ";" /bin/ls
// ./microshell /bin/ls "|" /usr/bin/grep microshell "|" /usr/bin/wc -l ";" /bin/echo hello world
