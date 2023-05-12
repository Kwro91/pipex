/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:40:12 by besalort          #+#    #+#             */
/*   Updated: 2023/05/12 15:11:18 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_command(char *command)
{
	char	*ptr;
	char	**commandp;

	ptr = ft_strchr(command, ' ');
	if (ptr != NULL)
		commandp = ft_split(command, ' ');
	else
	{
		commandp = ft_calloc(2, sizeof(char *));
		commandp[0] = ft_strdup(command);
	}
	return (commandp);
}
