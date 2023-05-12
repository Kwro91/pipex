/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:18:52 by besalort          #+#    #+#             */
/*   Updated: 2023/05/12 15:39:32 by besalort         ###   ########.fr       */
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

	data = (t_pipex){};
	if (ft_load(&data, ac, av, env) == -1)
		return (ft_msg("Error, argument\n"));
	ft_path_complete(&data, ft_path(env));
	if (ft_check_files(&data, data.file1.file, data.file2.file) == -1)
		return (ft_msg("Error, file\n"));
	run_processes(&data);
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
