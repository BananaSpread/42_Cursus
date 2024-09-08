/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:01:44 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/08 21:21:25 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	create_pipe(int (*fd_in_out)[2])
{
	if (pipe(*fd_in_out) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

static void	execute_parent(int pipe_fd[2], int fd_in_out[2],
	char **argv, char **envp)
{
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	dup2(fd_in_out[1], STDOUT_FILENO);
	close(fd_in_out[0]);
	close(fd_in_out[1]);
	exec_cmd(argv[3], envp);
}

static void	execute_child(int pipe_fd[2], int fd_in_out[2],
	char **argv, char **envp)
{
	close(pipe_fd[0]);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	dup2(fd_in_out[0], STDIN_FILENO);
	close(fd_in_out[0]);
	close(fd_in_out[1]);
	exec_cmd(argv[2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	int		fd_in_out[2];
	int		pid;

	if (argc != 5)
	{
		ft_print_str("Error: Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	fill_file_descriptors(argv, &fd_in_out);
	create_pipe(&pipe_fd);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		execute_child(pipe_fd, fd_in_out, argv, envp);
	else
		execute_parent(pipe_fd, fd_in_out, argv, envp);
}
