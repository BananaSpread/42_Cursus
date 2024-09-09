/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:57:21 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/09 20:49:47 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_cmd_params(char ***cmd_program, char **cmd_path)
{
	int	i;

	if (*cmd_program)
	{
		i = 0;
		while ((*cmd_program)[i])
		{
			free((*cmd_program)[i]);
			i++;
		}
		free(*cmd_program);
	}
	if (*cmd_path)
		free(*cmd_path);
}

static void	continue_exec_cmd(char ***cmd_program, char **cmd_path)
{
	if (!*cmd_path || access(*cmd_path, X_OK) == -1)
	{
		*cmd_path = concat_strs("Error: Command not found: ",
				*cmd_program[0], "\n");
		ft_putstr_fd(*cmd_path, STDERR_FILENO);
		free_cmd_params(cmd_program, cmd_path);
		exit(EXIT_FAILURE);
	}
	if (execve(*cmd_path, *cmd_program, NULL) == -1)
	{
		free_cmd_params(cmd_program, cmd_path);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	free_cmd_params(cmd_program, cmd_path);
}

void	exec_cmd(char *cmd_str, char **envp)
{
	char	**cmd_program;
	char	*cmd_path;

	if (ft_strlen(cmd_str) == 0)
	{
		ft_putstr_fd("Error: missing command\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	cmd_program = ft_split(cmd_str, ' ');
	if (!cmd_program)
	{
		perror("ft_split");
		exit(EXIT_FAILURE);
	}
	cmd_path = find_cmd_path(cmd_program[0], envp);
	continue_exec_cmd(&cmd_program, &cmd_path);
}
