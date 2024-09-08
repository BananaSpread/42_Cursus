/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:58:34 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/08 21:07:59 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fill_file_descriptors(char **argv, int (*fd_in_out)[2])
{
	(*fd_in_out)[0] = open(argv[1], O_RDONLY);
	if ((*fd_in_out)[0] == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	(*fd_in_out)[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if ((*fd_in_out)[1] == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
}

void	fill_env_paths(char **envp, char ***env_paths)
{
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			*env_paths = ft_split(*envp + 5, ':');
			if (!*env_paths)
			{
				perror("ft_split");
				exit(EXIT_FAILURE);
			}
			break ;
		}
		envp++;
	}
}
