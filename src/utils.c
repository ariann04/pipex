#include "pipex.h"

int	open_infile(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir infile");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	open_outfile(char *file)
{
	int	fd;

	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("Error al abrir outfile");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	execute_command(char *cmd, char **envp)
{
	char	**args;
	char	*path;

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
		exit(EXIT_FAILURE);
	}
	execve(path, args, envp);
	perror("pipex: execve");
	ft_free_tab(args);
	free(path);
	exit(EXIT_FAILURE);
}

char	*get_command_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*full_path;
	char	*tmp;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (paths && paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full_path, X_OK) == 0)
			return (ft_free_tab(paths), full_path);
		free(full_path);
	}
	ft_free_tab(paths);
	return (NULL);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
}

int	error_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (1);
}
