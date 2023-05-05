/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:00:04 by besalort          #+#    #+#             */
/*   Updated: 2023/05/05 18:41:04 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	algo(t_pipex *data)
{
	int	last;

	last = 0;
	while (data->lst)
	{
		if (data->lst->next == NULL)
			last = 1;
		ft_processes(data, data->lst->command, data->lst->cmd, last);
		data->lst = data->lst->next;
	}
}

void	ft_processes(t_pipex *data, char **cmdp, char *cmd, int last)
{
	int		pid;
	int		fd;

	fd = 0;
	pid = fork();
	(void)cmd;
	if (pid == 0)
	{
		if (last == 1)
		{
			printf("CECI NE S'AFFICHE QU'A LA DERNIERE COMMANDE\n");
		}
		else
		{
			fd = open("temporary_file", O_RDWR
				| O_CREAT, S_IRWXU);
			dup2(fd, 1);
		}
		execve(ft_access_cmd(data, cmdp[0]), cmdp, data->data.env);
		close(fd);
	}
	wait(NULL);
}
