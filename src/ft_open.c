/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:53:13 by besalort          #+#    #+#             */
/*   Updated: 2023/05/24 17:30:14 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_open_files(t_pipex *data, char *file1, char *file2)
{
	data->file1.fd = open(file1, O_RDONLY);
	data->file2.fd = open(file2, O_RDWR | O_TRUNC | O_CREAT,
			S_IRWXU);
}