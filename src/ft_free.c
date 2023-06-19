/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:08:01 by besalort          #+#    #+#             */
/*   Updated: 2023/06/19 17:37:25 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_give_fd(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

void	close_fds(t_pipex *data)
{
	if (data->file1.fd >= 0)
		close(data->file1.fd);
	if (data->file2.fd >= 0)
		close(data->file2.fd);
}

void	delete_list(t_lst *lst)
{
	if (lst->next != NULL)
		delete_list(lst->next);
	ft_free_paths(lst->command);
	free(lst);
}

void	ft_free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	if (paths)
		free(paths);
}

void	ft_free(t_pipex *data)
{
	int fd;
	if (data->paths)
		ft_free_paths(data->paths);
	if (data->lst)
		delete_list(data->lst);
	close_fds(data);
	fd =open(".here_doc_tmp", O_RDONLY);
	if (fd > 0)
	{
		close(fd);
		unlink(".here_doc_tmp");
	}
	exit(0);
}
