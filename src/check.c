/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:53:13 by besalort          #+#    #+#             */
/*   Updated: 2023/05/05 16:31:41 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_check_files(t_pipex *data, char *file1, char *file2)
{
	if (ft_open_files(data, file1, file2) == -1)
		return (-1);
	return (1);
}

int	ft_open_files(t_pipex *data, char *file1, char *file2)
{
	data->infile = open(file1, O_RDONLY);
	if (data->infile < 0)
		return (-1);
	data->fds[0] = data->infile;
	data->outfile = open (file2, O_RDWR | O_TRUNC | O_CREAT,
			S_IRWXU);
	if (data->outfile < 0)
		return (-1);
	data->fds[1] = data->outfile;
	return (1);
}
