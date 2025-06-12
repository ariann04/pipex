#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
#include <sys/wait.h>

void	child_process(char **argv, int *pipefd, char **envp);
void	parent_process(char **argv, int *pipefd, char **envp);
void	execute_command(char *cmd, char **envp);
char	*get_command_path(char *cmd, char **envp);
int		open_infile(char *file);
int		open_outfile(char *file);
void	ft_free_tab(char **tab);
int		error_msg(char *msg);

#endif
