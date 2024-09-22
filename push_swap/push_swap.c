/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:27:27 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/22 18:27:27 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stacks(t_stacks *stacks)
{
	if ((*stacks).stack_a)
		free((*stacks).stack_a);
	if ((*stacks).stack_b)
		free((*stacks).stack_b);
}

static void	init_stacks(t_stacks *stacks, int argc, char *argv[])
{
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit(1);
	else if (argc == 2)
		(*stacks).stack_a = parse_grouped_arguments(argv[1]);
	else
		(*stacks).stack_a = parse_arguments(argc, argv, 1);
	if (!(*stacks).stack_a)
		exit(1);
	if (!((*stacks).stack_b = malloc(sizeof(int) * argc)))
	{
		free_stacks(stacks);
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	init_stacks(&stacks, argc, argv);
	

	// int i = 0;
	// while (stacks.stack_a[i] != '\0')
	// 	ft_printf("Num: %d\n", stacks.stack_a[i++]);
	free_stacks(&stacks);
	return (0);
}
