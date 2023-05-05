/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:27:50 by besalort          #+#    #+#             */
/*   Updated: 2023/05/05 18:30:29 by besalort         ###   ########.fr       */
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

typedef struct s_lst
{
	char	*cmd;
	char	**command;
	void	*next;
}	t_lst;

typedef struct s_data
{
	int		ac;
	char	**av;
	char	**env;
}	t_data;

typedef struct s_file
{
	char	*file1;
	char	*file2;
}	t_file;

typedef struct s_pipex
{
	int			infile;
	int			outfile;
	int			cmds;
	int			fds[2];
	char		**paths;
	pid_t		child[2];
	t_file		file;
	t_lst		*lst;
	t_data		data;
}	t_pipex;
// FT_CHECK.C //
int		ft_check_files(t_pipex *data, char *file1, char *file2);
int		ft_open_files(t_pipex *data, char *file1, char *file2);
// FT_ACCESS.C //
char	*ft_access_cmd(t_pipex *data, char *cmd);
char	*ft_modify_cmd(char *cmd);
// FT_CMD.C //
char	**ft_command(char *coammand);
// FT_FREE.C //
void	ft_free_paths(char **paths);
void	ft_free(t_pipex *data);
// FT_PATH.C //
char	**ft_path(char **env);
void	ft_path_complete(t_pipex *data, char **paths);
// FT_LIST.C //
t_lst	*createlist(int size, char **command, t_pipex *data);
// FT_LOAD.C //
void	ft_listload(t_pipex *data, char **av);
void	ft_load_av(t_pipex *data, int ac, char **av);
int		ft_load(t_pipex *data, int ac, char **av, char **env);
// FT_pipex.C //
void	ft_pipex(int ac, char **av, char **env);
void	ft_msg(char *msg);
// PROCESSES.C //
void	algo(t_pipex *data);
void	ft_processes(t_pipex *data, char **cmdp, char *cmd, int last);
#endif