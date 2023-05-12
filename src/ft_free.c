/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:08:01 by besalort          #+#    #+#             */
/*   Updated: 2023/05/12 16:55:09 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fds(t_pipex *data)
{
	close(data->file1.fd);
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
	if (data->paths)
		ft_free_paths(data->paths);
	if (data->infile >= 0)
		close(data->infile);
	if (data->outfile >= 0)
		close(data->outfile);
	if (data->lst)
		delete_list(data->lst);
	close_fds(data);
	exit(0);
}
