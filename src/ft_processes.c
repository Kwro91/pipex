/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:00:04 by besalort          #+#    #+#             */
/*   Updated: 2023/05/10 17:32:25 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	algo(t_pipex *data)
{
	int	i;

	i = 0;
	pipe(data->fds);
	while (data->lst)
	{
		if (data->lst->next == NULL)
			ft_processes(data, data->lst->command, 1);
		else
			ft_processes(data, data->lst->command, 0);
		data->lst = data->lst->next;
	}
	while (i < data->cmds)
	{
		wait(NULL);
		i++;
	}
}

void	ft_processes(t_pipex *data, char **cmdp, int last)
{
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		if (last == 1)
		{
			close(data->fds[1]);
			dup2(data->fds[0], 0);
			dup2(data->file2.fd, 1);
			// close(data->fds[0]);
			ft_printf("CECI NE S'AFFICHE QU'A LA DERNIERE COMMANDE\n");
		}
		else
		{
			close(data->fds[0]);
			dup2(data->file1.fd, 0);
			dup2(data->fds[1], 1);
		}
		execve(ft_access_cmd(data, cmdp[0]), cmdp, data->data.env);
	}
	ft_putstr_fd("salut fils\n", data->fds[1]);
	if (last == 0)
	{
		close(data->fds[0]);
		close(data->fds[1]);
	}
}
