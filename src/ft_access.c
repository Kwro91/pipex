/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:44:57 by besalort          #+#    #+#             */
/*   Updated: 2023/05/05 16:42:02 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_modify_cmd(char *cmd)
{
	int		i;
	char	*tmp;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == ' ')
			break ;
		i++;
	}
	tmp = ft_substr(cmd, 0, i);
	cmd = tmp;
	return (cmd);
}

int	ft_access_cmd1(t_pipex *data)
{
	char	*join;
	char	*tmp;
	int		i;

	i = 0;
	data->cmd.cmd1 = ft_modify_cmd(data->cmd.cmd1);
	while (data->paths[i])
	{
		tmp = ft_strjoin(data->paths[i], "/");
		join = ft_strjoin(tmp, data->cmd.cmd1);
		if (access(join, X_OK) == 0)
		{
			free(join);
			free(tmp);
			return (1);
		}
		free(join);
		free(tmp);
		i++;
	}
	return (0);
}

int	ft_access_cmd2(t_pipex *data)
{
	char	*join;
	char	*tmp;
	int		i;

	i = 0;
	data->cmd.cmd2 = ft_modify_cmd(data->cmd.cmd2);
	while (data->paths[i])
	{
		tmp = ft_strjoin(data->paths[i], "/");
		join = ft_strjoin(tmp, data->cmd.cmd2);
		if (access(join, X_OK) == 0)
		{
			free(join);
			free(tmp);
			return (1);
		}
		free(join);
		free(tmp);
		i++;
	}
	return (0);
}

int	ft_access(t_pipex *data)
{
	if (ft_access_cmd1(data) == 1)
	{
		if (ft_access_cmd2(data) == 1)
			return (3);
		else
		{
			ft_printf("Error, cmd2 unvailable\n");
			return (1);
		}
	}
	else
	{
		if (ft_access_cmd2(data) == 1)
		{
			ft_printf("Error, cmd1 unvailable\n");
			return (2);
		}
	}
	ft_printf("Error, cmd1 && cmd2 unvailable\n");
	return (0);
}

char	*ft_access_cmd(t_pipex *data, char *cmd)
{
	char	*join;
	char	*tmp;
	int		i;

	i = 0;
	while (data->paths[i])
	{
		tmp = ft_strjoin(data->paths[i], "/");
		join = ft_strjoin(tmp, cmd);
		if (access(join, X_OK) == 0)
			return (free(tmp), join);
		free(join);
		free(tmp);
		i++;
	}
	return (NULL);
}
