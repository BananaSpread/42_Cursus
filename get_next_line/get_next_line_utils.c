/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:56:49 by idel-poz          #+#    #+#             */
/*   Updated: 2024/04/06 16:45:04 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	str_has_line_break(t_str_stack *stack)
{
	int	i;

	if (!stack)
		return (0);
	while (stack)
	{
		i = 0;
		while (stack->buf[i] && i < BUFFER_SIZE)
		{
			if (stack->buf[i] == '\n')
				return (1);
			i++;
		}
		stack = stack->next;
	}
	return (0);
}

int	get_line_len(t_str_stack *stack)
{
	int	len;
	int	i;

	len = 0;
	while (stack)
	{
		i = 0;
		while (stack->buf[i])
		{
			if (stack->buf[i] == '\n')
				return (len + 1);
			len++;
			i++;
		}
		stack = stack->next;
	}
	return (len);
}

t_str_stack	*get_last_stack(t_str_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

char	*get_remaining_buffer(t_str_stack **stack)
{
	t_str_stack	*last;
	char		*buf;
	int			i;
	int			j;

	last = get_last_stack(*stack);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	i = 0;
	j = 0;
	while (last->buf[i] && last->buf[i] != '\n')
		i++;
	while (last->buf[i] && last->buf[++i])
		buf[j++] = last->buf[i];
	buf[j] = 0;
	i = 0;
	while (buf[i])
		i++;
	if (i == 0)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

void	clean_stack(t_str_stack **stack)
{
	t_str_stack	*tmp;
	char		*buf;

	buf = get_remaining_buffer(stack);
	while (*stack)
	{
		tmp = (*stack)->next;
		free((*stack)->buf);
		free(*stack);
		*stack = tmp;
	}
	free(*stack);
	if (!buf || !buf[0])
		return ;
	*stack = malloc(sizeof(t_str_stack));
	if (!*stack)
		return ;
	(*stack)->buf = buf;
	(*stack)->next = NULL;
}
