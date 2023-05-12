/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:00:04 by besalort          #+#    #+#             */
/*   Updated: 2023/05/12 15:53:44 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_processes(t_pipex *data)
{
	int	i;

	i = 0;
	pipe(data->fds);
	printf("PARENT = 1er %i, 2eme %i\n", data->fds[0], data->fds[1]);
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
			printf("DERNIER ENFANT = 1er %i, 2eme %i\n", data->fds[0], data->fds[1]);
			close(data->fds[1]);
			dup2(data->fds[0], 0);
			dup2(data->file2.fd, 1);
			//close(data->fds[0]);
		}
		else
		{
			printf("ENFANT = 1er %i, 2eme %i\n", data->fds[0], data->fds[1]);
			close(data->fds[0]);
			dup2(data->file1.fd, 0);
			dup2(data->fds[1], 1);
			//close(data->fds[1]);
		}
		execve(ft_access_cmd(data, cmdp[0]), cmdp, data->data.env);
	}
}
