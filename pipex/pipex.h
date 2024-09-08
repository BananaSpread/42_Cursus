/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:06:33 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/08 20:58:19 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>
# include <string.h>

void	fill_file_descriptors(char **argv, int (*fd_in_out)[2]);
void	fill_env_paths(char **envp, char ***env_paths);

char	*concat_strs(char *str1, char *str2, char *str3);
char	*find_cmd_path(char *cmd, char **envp);

void	exec_cmd(char *cmd_str, char **envp);

#endif