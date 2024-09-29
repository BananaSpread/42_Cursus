/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:02:54 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/29 18:07:47 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack_node
{
	long				value;
	size_t				index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

void			sort_stack(t_stack_node **stack);
void			tiny_sort(t_stack_node **stack_a);

// STACK //
int				get_min_value(t_stack_node *stack);
int				get_max_value(t_stack_node *stack);
int				get_stack_size(t_stack_node *stack);
int				check_if_sorted(t_stack_node *stack);

// PARSER //
void			parse_arguments(t_stack_node **stack_a, char *argv[], int i);
void			parse_grouped_arguments(t_stack_node **stack_a, char *args);

// SOLVER //
int				check_case_ra_rb(t_stack_node *a, t_stack_node *b, int c);
int				check_case_rra_rrb(t_stack_node *a, t_stack_node *b, int c);
int				check_case_rra_rb(t_stack_node *a, t_stack_node *b, int c);
int				check_case_ra_rrb(t_stack_node *a, t_stack_node *b, int c);

int				check_case_ra_rb_a(t_stack_node *a, t_stack_node *b, int c);
int				check_case_rra_rrb_a(t_stack_node *a, t_stack_node *b, int c);
int				check_case_ra_rrb_a(t_stack_node *a, t_stack_node *b, int c);	
int				check_case_rra_rb_a(t_stack_node *a, t_stack_node *b, int c);

// ROTATE //
int				rotate_type_ab(t_stack_node *a, t_stack_node *b);
int				rotate_type_ba(t_stack_node *a, t_stack_node *b);

int				apply_ra_rb(t_stack_node **a, t_stack_node **b, int c, char s);
int				apply_rra_rrb(t_stack_node **a, t_stack_node **b,
					int c, char s);
int				apply_rra_rb(t_stack_node **a, t_stack_node **b, int c, char s);
int				apply_ra_rrb(t_stack_node **a, t_stack_node **b, int c, char s);

// FIND //
t_stack_node	*find_last_node(t_stack_node *stack);
int				find_index(t_stack_node *stack, int value);
int				find_place_b(t_stack_node *stack_b, int value_push);	
int				find_place_a(t_stack_node *stack_a, int value_push);

// MOVEMENTS //
void			pa(t_stack_node **a, t_stack_node **b, int j);
void			pb(t_stack_node **stack_a, t_stack_node **stack_b, int j);
void			ra(t_stack_node **a, int j);
void			rb(t_stack_node **b, int j);
void			rr(t_stack_node **a, t_stack_node **b, int j);
void			rra(t_stack_node **a, int j);
void			rrb(t_stack_node **b, int j);
void			rrr(t_stack_node **a, t_stack_node **b, int j);
void			sa(t_stack_node **a, int j);
void			sb(t_stack_node **b, int j);
void			ss(t_stack_node **a, t_stack_node **b, int j);

// CLEANER //
void			free_stack(t_stack_node **stack);
void			free_argv(char **argv);

#endif