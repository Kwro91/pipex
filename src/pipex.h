/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:27:50 by besalort          #+#    #+#             */
/*   Updated: 2023/05/05 16:31:03 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include <fcntl.h>

typedef struct s_data
{
	int		ac;
	char	**av;
	char	**env;
}	t_data;

typedef struct s_usercmd
{
	char	*file1;
	char	*file2;
	char	*cmd1;
	char	*cmd2;
	char	**command1;
	char	**command2;
}	t_usercmd;

typedef struct s_pipex
{
	int			infile;
	int			outfile;
	int			cmds;
	int			fds[2];
	pid_t		child[2];
	char		**paths;
	t_usercmd	cmd;
	t_data		data;
}	t_pipex;
// FT_CHECK.C //
int		ft_check_files(t_pipex *data, char *file1, char *file2);
int		ft_open_files(t_pipex *data, char *file1, char *file2);
// FT_ACCESS.C //
int		ft_access(t_pipex *data);
int		ft_access_cmd1(t_pipex *data);
int		ft_access_cmd2(t_pipex *data);
char	*ft_access_cmd(t_pipex *data, char *cmd);
char	*ft_modify_cmd(char *cmd);
// FT_CMD.C //
void	ft_command(t_pipex *data);
// FT_FREE.C //
void	ft_free_cmd(t_pipex *data);
void	ft_free_paths(char **paths);
void	ft_free(t_pipex *data);
// FT_PATH.C //
char	**ft_path(char **env);
void	ft_path_complete(t_pipex *data, char **paths);
// FT_LOAD.C //
int		ft_load(t_pipex *data, int ac, char **av, char **env);
// FT_pipex.C //
void	ft_pipex(int ac, char **av, char **env);
void	ft_msg(char *msg);
// PROCESSES.C //
void	ft_processes(t_pipex *data, char **av, char *cmd, int nb);
#endif