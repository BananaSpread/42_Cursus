/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:27:27 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/21 13:03:47 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_init_stack(char *argv[])
{
	int	*stack_a;
	int	i;

	i = 0;
	while (argv[i])
		i++;
	stack_a = malloc(sizeof(int) * i + 1);
	if (!stack_a)
		return (0);
	i = 0;
	while (argv[i])
	{
		stack_a[i] = ft_atoi(argv[i]);
		if (stack_a[i] == 0)
		{
			free(stack_a);
			return (0);
		}
		// TODO: check if the number is not bigger than int
		i++;
	}
	stack_a[i] = '\0';
	return (stack_a);
}

int	main(int argc, char *argv[])
{
	int	*stack_a;
	int	*stack_b;

	if (argc < 2)
		return (0);
	if ((stack_a = ft_init_stack(argv)) == 0)
		return (0);
	if (!(stack_b = malloc(sizeof(int) * (argc - 1))))
	{
		free(stack_a);
		return (0);
	}

	return (0);
}
