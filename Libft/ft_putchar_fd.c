/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:47:32 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/27 13:42:13 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Put the char c in the specific output fd.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
