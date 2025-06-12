#include "pipex.h"

void	child_process(char **argv, int *pipefd, char **envp)
{
	int	infile;

	infile = open_infile(argv[1]);
	dup2(infile, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	execute_command(argv[2], envp);
}

void	parent_process(char **argv, int *pipefd, char **envp)
{
	int	outfile;

	outfile = open_outfile(argv[4]);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	execute_command(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (argc != 5)
		return (error_msg("Uso: ./pipex infile cmd1 cmd2 outfile\n"));
	if (pipe(pipefd) == -1)
		return (error_msg("Error al crear el pipe\n"));
	pid = fork();
	if (pid == -1)
		return (error_msg("Error al hacer fork\n"));
	if (pid == 0)
		child_process(argv, pipefd, envp);
	waitpid(pid, NULL, 0);
	parent_process(argv, pipefd, envp);
	return (0);
}
