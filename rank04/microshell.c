#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

//Temp file
int	g_temp;

//Function writes string to STDERR
int	we(const char *str)
{
	while (*str)
		write(STDERR_FILENO, str++, 1);
	return (EXIT_FAILURE);
}

//Function performs directory change
int	cd(char **argv, int i)
{
	if (i != 2)
		return (we("error: cd: bad arguments\n"));
	if (chdir(argv[1]))
	{
		we("error: cd: cannot change directory to ");
		we(argv[1]);
		return (we("\n"));
	}
	return (EXIT_SUCCESS);
}

//Function executes command line
int	ex(char **argv, char **env, int i)
{
	int	files[2];
	int	pid, ret;
	int pip = (argv[i] && !strcmp(argv[i], "|"));

	if (pip && pipe(files))
		return (we("error: fatal\n"));
	pid = fork();
	if (!pid)
	{
		argv[i] = NULL;
		if ((dup2(g_temp, STDIN_FILENO) == -1 | close(g_temp) == -1) | \
			(pip && dup2(files[1], STDOUT_FILENO) == -1 | close(files[0]) == -1 | close(files[1]) == -1))
			return (we("error: fatal\n"));
		execve(*argv, argv, env);
		we("error: cannot execute ");
		we(*argv);
		return (we("\n"));
	}
	if ((pip && dup2(files[0], g_temp) == -1 | close(files[0]) == -1 | close(files[1]) == -1) | \
		(!pip && dup2(STDIN_FILENO, g_temp) == -1) | \
		waitpid(pid, &ret, 0) == -1)
		return (we("error: fatal\n"));
	return (WIFEXITED(ret) && WEXITSTATUS(ret));
}

//Program is a small command line executor
int	main(int argc, char **argv, char **env)
{
	int	i = 0;
	int	ret = EXIT_SUCCESS;

	(void) argc;
	g_temp = dup(STDIN_FILENO);
	while (argv[i] && argv[++i])
	{
		argv += i;
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (!strcmp(*argv, "cd"))
			ret = cd(argv, i);
		else if (i)
			ret = ex(argv, env, i);
	}
	ret = (dup2(STDIN_FILENO, g_temp) == -1 && we("error: fatal\n")) | ret;
	return (ret);
}
