/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:41:29 by besalort          #+#    #+#             */
/*   Updated: 2023/05/31 15:45:04 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_here_doc(t_pipex *data)
{
	char *str;

	str = "here_doc";
	if (ft_strncmp(data->data.av[1], str, ft_strlen(data->data.av[1])) == 0)
	{
		
	}
}