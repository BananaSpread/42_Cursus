/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:01:44 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/07 21:02:03 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int	fd_in;
	int pipe_fd[2];

	if (argc != 5)
	{
		ft_print_str("Error: Wrong number of arguments\n");
		return (1);
	}
	
	return (0);
}