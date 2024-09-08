/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:59:33 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/08 21:10:51 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_env_paths(char ***env_paths)
{
	int	i;

	i = 0;
	while ((*env_paths)[i])
		free((*env_paths)[i++]);
	free(*env_paths);
}

char	*concat_strs(char *str1, char *str2, char *str3)
{
	char	*concat_str;
	int		size;

	size = ft_strlen(str1) + ft_strlen(str2) + ft_strlen(str3) + 1;
	concat_str = malloc(size * sizeof(char));
	if (!concat_str)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	ft_strlcpy(concat_str, str1, size);
	ft_strlcat(concat_str, str2, size);
	ft_strlcat(concat_str, str3, size);
	concat_str[size] = '\0';
	return (concat_str);
}

char	*find_cmd_path(char *cmd, char **envp)
{
	char	*cmd_path;
	char	**env_paths;
	int		i;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	fill_env_paths(envp, &env_paths);
	i = 0;
	while (env_paths[i])
	{
		cmd_path = concat_strs(env_paths[i], "/", cmd);
		if (access(cmd_path, X_OK) == 0)
		{
			free_env_paths(&env_paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free_env_paths(&env_paths);
	return (NULL);
}
