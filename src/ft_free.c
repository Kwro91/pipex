/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:08:01 by besalort          #+#    #+#             */
/*   Updated: 2023/05/05 16:33:05 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_cmd(t_pipex *data)
{
	int	i;

	i = 0;
	if (data->cmd.cmd1)
		free(data->cmd.cmd1);
	if (data->cmd.cmd2)
		free(data->cmd.cmd2);
	if (data->cmd.command1)
	{
		while (data->cmd.command1[i])
		{
			free(data->cmd.command1[i]);
			i++;
		}
		free(data->cmd.command1);
	}
	i = 0;
	if (data->cmd.command2)
	{
		while (data->cmd.command2[i])
		{
			free(data->cmd.command2[i]);
			i++;
		}
		free(data->cmd.command2);
	}
}

void	ft_free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

void	ft_free(t_pipex *data)
{
	ft_free_cmd(data);
	if (data->paths)
		ft_free_paths(data->paths);
	if (data->infile > 0)
		close(data->infile);
	if (data->outfile > 0)
		close(data->outfile);
	exit(0);
}
