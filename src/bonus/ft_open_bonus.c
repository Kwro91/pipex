/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:53:13 by besalort          #+#    #+#             */
/*   Updated: 2023/07/06 16:16:44 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_open_files(t_pipex *data, char *file1, char *file2)
{
	if (data->here_doc == 0)
		data->file1.fd = open(file1, O_RDONLY);
	else
		data->file1.fd = open(".here_doc_tmp", O_RDONLY);
	data->file2.fd = open(file2, O_RDWR | O_TRUNC | O_CREAT,
			S_IRWXU);
	if (data->file1.fd < 0)
	{
		ft_msg(": no such file or directory: ");
		ft_msg(file1);
		ft_msg("\n");
	}
}
