/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:51:40 by besalort          #+#    #+#             */
/*   Updated: 2023/05/05 16:42:25 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_load_av(t_pipex *data, char **av)
{
	data->cmd.file1 = av[1];
	data->cmd.cmd1 = av[2];
	data->cmd.cmd2 = av[3];
	data->cmd.file2 = av[4];
}

int	ft_load(t_pipex *data, int ac, char **av, char **env)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (!av[i])
			return (-1);
		i++;
	}
	data->data.ac = ac;
	data->cmds = ac - 3;
	ft_load_av(data, av);
	data->data.av = av;
	if (env)
		data->data.env = env;
	else
	{
		data->data.env = malloc(sizeof(char *) * 2);
		if (!data->data.env)
			return (free(data->data.env), -1);
		data->data.env[0] = "/usr/bin/env";
		data->data.env[1] = NULL;
	}
	data->fds[0] = 0;
	return (1);
}
