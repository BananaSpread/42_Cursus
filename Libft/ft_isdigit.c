/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:31:40 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/21 15:39:59 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Checks if c is a valid number char
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
