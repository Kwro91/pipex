/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:53:13 by besalort          #+#    #+#             */
/*   Updated: 2023/05/08 15:47:37 by besalort         ###   ########.fr       */
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
	data->file1.fd = open(file1, O_RDONLY);
	if (data->file1.fd < 0)
		return (-1);
	data->fds[0] = data->infile;
	data->file2.fd = open (file2, O_RDWR | O_TRUNC | O_CREAT,
			S_IRWXU);
	if (data->file2.fd < 0)
		return (-1);
	data->fds[1] = data->outfile;
	return (1);
}
