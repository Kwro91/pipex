/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:18:52 by besalort          #+#    #+#             */
/*   Updated: 2023/05/05 16:38:52 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_msg(char *msg)
{
	ft_putstr_fd(msg, 1);
}

void	ft_pipex(int ac, char **av, char **env)
{
	t_pipex	data;
	int		i;

	i = -1;
	data = (t_pipex){};
	if (ft_load(&data, ac, av, env) == -1)
		return (ft_msg("Error, argument\n"));
	ft_command(&data);
	ft_path_complete(&data, ft_path(env));
	if (ft_access(&data) == 0)
		return (ft_free(&data));
	if (ft_check_files(&data, data.cmd.file1, data.cmd.file2) == -1)
		return (ft_msg("Error, file\n"));
	while (++i < data.cmds)
		ft_processes(&data, data.cmd.command1, data.cmd.cmd1, 1);
	return (ft_free(&data));
}

int	main(int ac, char **av, char **env)
{
	if (ac >= 5)
		ft_pipex(ac, av, env);
	else
		ft_msg("Error, Wrong nb of arg\n");
	return (0);
}
