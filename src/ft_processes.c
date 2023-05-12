/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:00:04 by besalort          #+#    #+#             */
/*   Updated: 2023/05/12 16:54:16 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_processes(t_pipex *data)
{
	int	i;
	t_lst *tmp;

	tmp = data->lst;
	i = 0;
	pipe(data->fds);
	while (tmp)
	{
		if (tmp->next == NULL)
			ft_processes(data, tmp->command, 1);
		else
			ft_processes(data, tmp->command, 0);
		tmp = tmp->next;
	}
	
	while (i < data->cmds)
	{
		wait(NULL);
		if (i == 0)
		{
			close(data->fds[1]);
			close(data->fds[0]);
		}
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
		}
		else
		{
			close(data->fds[0]);
			dup2(data->file1.fd, 0);
			dup2(data->fds[1], 1);
		}
		execve(ft_access_cmd(data, cmdp[0]), cmdp, data->data.env);
	}
}
