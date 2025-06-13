#include "pipex.h"

void    execute_command(char *cmd, char **envp)
{
        char    **args;
        char    *path;

        args = ft_split(cmd, ' ');
        if (!args || !args[0])
        {
                ft_putstr_fd("pipex: comando vacío\n", 2);
                exit(EXIT_FAILURE);
        }
        path = get_command_path(args[0], envp);
        if (!path)
        {
                ft_putstr_fd("pipex: command not found: ", 2);
                ft_putendl_fd(args[0], 2);
                ft_free_tab(args);
                exit(127);
        }
        execve(path, args, envp);
        perror("pipex: execve");
        ft_free_tab(args);
        free(path);
        exit(127);
}

void	child_process(char **argv, int *fd, char **envp)
{
	int	infile;

	infile = open_infile(argv[1]);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execute_command(argv[2], envp);
}

void	parent_process(char **argv, int *fd, char **envp)
{
	int	outfile;

	outfile = open_outfile(argv[4]);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execute_command(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		return (error_msg("Uso: ./pipex infile cmd1 cmd2 outfile\n"));
	if (pipe(fd) == -1)
		return (error_msg("Error al crear el pipe\n"));
	pid = fork();
	if (pid == -1)
		return (error_msg("Error al hacer fork\n"));
	if (pid == 0)
		child_process(argv, fd, envp);
	waitpid(pid, NULL, 0);
	parent_process(argv, fd, envp);
	return (0);
}
