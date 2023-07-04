/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:00:04 by besalort          #+#    #+#             */
/*   Updated: 2023/07/03 17:04:20 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_first_process(t_pipex *data, char **cmdp, int pipes[2])
{
	int		pid;
	char	*path;

	path = ft_access_cmd(data, cmdp[0]);
	pid = fork();
	if (pid == -1)
		return (perror("Error fork\n"), ft_free(data));
	else if (pid == 0)
	{
		if (data->fd_in >= 0)
		{
			if (dup2(data->fd_in, 0) < 0)
				return (ft_free(data));
			close(data->fd_in);
		}
		if (dup2(pipes[1], 1) < 0)
			return (ft_free(data));
		close_give_fd(pipes[1], pipes[0]);
		exit(execve(path, cmdp, data->data.env));
	}
}

void	ft_processes(t_pipex *data, char **cmdp, int pipes[2])
{
	int		pid;
	char	*path;

	path = ft_access_cmd(data, cmdp[0]);
	pid = fork();
	if (pid == -1)
		return (perror("Error fork\n"), ft_free(data));
	else if (pid == 0)
	{
		if (dup2(data->fd_in, 0) < 0 || dup2(pipes[1], 1) < 0)
			return (ft_free(data));
		close(data->fd_in);
		close_give_fd(pipes[1], pipes[0]);
		exit(execve(path, cmdp, data->data.env));
	}
}

void	ft_last_process(t_pipex *data, char **cmdp, int pipes[2])
{
	int		pid;
	char	*path;

	path = ft_access_cmd(data, cmdp[0]);
	if (path == NULL)
		data->status = 127;
	pid = fork();
	if (pid == -1)
		return (perror("Error fork\n"), ft_free(data));
	else if (pid == 0)
	{
		if (dup2(data->fd_in, 0) < 0 || dup2(data->file2.fd, 1) < 0)
			return (ft_free(data));
		close(data->fd_in);
		close_give_fd(pipes[1], pipes[0]);
		exit(execve(path, cmdp, data->data.env));
	}
}
