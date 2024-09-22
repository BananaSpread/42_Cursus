/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:02:54 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/22 18:18:47 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stacks
{
	int	*stack_a;
	int	*stack_b;
	int	stack_size;
}	t_stacks;

int 	*parse_arguments(int size, char *argv[], int i);
int		*parse_grouped_arguments(char *args);

void	free_and_error(void *m);

#endif