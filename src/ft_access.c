/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:44:57 by besalort          #+#    #+#             */
/*   Updated: 2023/05/05 18:41:17 by besalort         ###   ########.fr       */
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
	join = ft_strjoin("command not found: ", cmd);
	perror(join);
	return (free(join), NULL);
}
