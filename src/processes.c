/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:00:04 by besalort          #+#    #+#             */
/*   Updated: 2023/05/05 16:37:40 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_processes(t_pipex *data, char **argv, char *cmd, int nb)
{
	int		pid;
	int		tab[2];
	int		fdtemp;

	tab[0] = 0;
	tab[1] = 0;
	fdtemp = 0;
	pid = fork();
	if (pid == 0)
	{
		if (nb == 1)
			dup2(data->infile, 0);
		if (nb == 1)
		{
			fdtemp = open("temporary_file", O_RDWR | O_TRUNC
					| O_CREAT, S_IRWXU);
			dup2(fdtemp, 1);
		}
		else
		{
			dup2(tab[0], 0);
			dup2(tab[1], 1);
		}
		execve(ft_access_cmd(data, cmd), argv, data->data.env);
		if (nb == 1)
			close(data->infile);
	}
	wait(NULL);
}
