/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:35:45 by idel-poz          #+#    #+#             */
/*   Updated: 2024/01/21 15:41:08 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Checks if c is a valid alphanumeric char
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
