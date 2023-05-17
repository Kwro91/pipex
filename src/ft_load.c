/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:51:40 by besalort          #+#    #+#             */
/*   Updated: 2023/05/17 17:30:40 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_load_av(t_pipex *data, int ac, char **av)
{
	data->file1.file = av[1];
	data->file2.file = av[ac - 1];
}

void	ft_listload(t_pipex *data, char **av)
{
	data->lst = createlist(data->cmds, av + 2, data);
}

void	ft_load_env(t_pipex *data, char **env)
{
	char	*envbis;

	envbis = "/usr/bin/env";
	if (env)
		data->data.env = env;
	else
	{
		data->data.env = malloc(sizeof(char *) * 2);
		if (!data->data.env)
		{
			free(data->data.env[0]);
			free(data->data.env[1]);
			return (free(data->data.env));
		}
		data->data.env[0] = ft_strdup(envbis);
		data->data.env[1] = NULL;
	}
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
	ft_listload(data, av);
	ft_load_av(data, ac, av);
	data->data.av = av;
	ft_load_env(data, env);
	return (1);
}
