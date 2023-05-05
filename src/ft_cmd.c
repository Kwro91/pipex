/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:40:12 by besalort          #+#    #+#             */
/*   Updated: 2023/05/05 16:42:43 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_command(t_pipex *data)
{
	char	*ptr;

	ptr = ft_strchr(data->cmd.cmd1, ' ');
	if (ptr != NULL)
		data->cmd.command1 = ft_split(data->cmd.cmd1, ' ');
	else
		data->cmd.command1 = ft_calloc(2, 1);
	ptr = ft_strchr(data->cmd.cmd2, ' ');
	if (ptr != NULL)
		data->cmd.command2 = ft_split(data->cmd.cmd2, ' ');
	else
		data->cmd.command2 = ft_calloc(2, 1);
}
