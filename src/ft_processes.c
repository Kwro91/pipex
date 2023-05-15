/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:00:04 by besalort          #+#    #+#             */
/*   Updated: 2023/05/15 17:44:03 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_processes(t_pipex *data)
{
	int		i;
	t_lst	*tmp;

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
			if (dup2(data->fds[0], 0) < 0 || dup2(data->file2.fd, 1) < 0)
				return (perror("Error dup2\n"), ft_free(data));
			close_give_fd(data->fds[1], data->fds[0]);
		}
		else
		{
			if (data->file1.fd >= 0)
			{
				if (dup2(data->file1.fd, 0) < 0)
					return (perror("Error dup2\n"), ft_free(data));
			}
			if (dup2(data->fds[1], 1) < 0)
				return (ft_msg("Error dup2\n"), ft_free(data));
			close_give_fd(data->fds[1], data->fds[0]);
		}
		execve(ft_access_cmd(data, cmdp[0]), cmdp, data->data.env);
	}
}
