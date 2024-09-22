/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:27:27 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/22 14:46:14 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	*stack_a;
	int	*stack_b;

	if (argc < 2)
		return (0);
	if ((stack_a = parse_arguments(argc, argv)) == NULL)
		return (0);
	if (!(stack_b = malloc(sizeof(int) * argc)))
	{
		free(stack_a);
		return (0);
	}
	for (int i = 0; i < argc - 1; i++)
		ft_printf("stack_a[%d] = ", i);
	free(stack_a);
	free(stack_b);
	return (0);
}
