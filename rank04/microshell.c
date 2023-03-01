/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:34:42 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/01 14:37:09 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

//Working file descriptor.
int	g_temp;

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
	if (i != 2)
		return (write_error("error: cd: bad arguments\n"));
	if (chdir(argv[1]))
	{
		write_error("error: cd: cannot change directory to ");
		write_error(argv[1]);
		return (write_error("\n"));
	}
	return (EXIT_SUCCESS);
}

//Function performs the child process actions.
int	child(char **argv, char **env, int i, int *arr[3])
{
	argv[i] = 0;
	if (dup2(g_temp, STDIN_FILENO) == -1 | close(g_temp) == -1 | \
		(*arr[0] && (dup2(*arr[2], STDOUT_FILENO)) == -1 | \
		close(*arr[1]) == -1 | close(*arr[2]) == -1))
		return (write_error("error: fatal\n"));
	execve(*argv, argv, env);
	write_error("error: cannot execute ");
	write_error(*argv);
	return (write_error("\n"));
}

//Function executes command line starting with i argument.
int	execute(char **argv, char **env, int i)
{
	int	pip;
	int	pid;
	int	ret;
	int	files[2];
	int	*childarr[3];

	childarr[0] = &pip;
	childarr[1] = &files[0];
	childarr[2] = &files[1];
	pip = (argv[i] && !strcmp(argv[i], "|"));
	if (pip && pipe(files))
		return (write_error("error: fatal\n"));
	pid = fork();
	if (!pid)
		return (child(argv, env, i, childarr));
	if ((pip && (dup2(files[0], g_temp) == -1 | close(files[0]) == -1 | \
		close(files[1]) == -1)) | (!pip && dup2(STDIN_FILENO, g_temp) == -1) \
		| waitpid(pid, &ret, 0) == -1)
		return (write_error("error: fatal\n"));
	return (WIFEXITED(ret) && WEXITSTATUS(ret));
}

//Program is a small command line executor.
int	main(int argc, char **argv, char **env)
{
	int	i;
	int	ret;

	(void) argc;
	g_temp = dup(STDIN_FILENO);
	ret = EXIT_SUCCESS;
	i = 0;
	while (argv[i] && argv[++i])
	{
		argv += i;
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (!strcmp(*argv, "cd"))
			ret = cd(argv, i);
		else if (i)
			ret = execute(argv, env, i);
	}
	ret = ((dup2(STDIN_FILENO, g_temp) == -1) && \
			write_error("error: fatal\n")) | ret;
	return (ret);
}
