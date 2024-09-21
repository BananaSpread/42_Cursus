/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:56:54 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/21 12:56:45 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	append_to_stack(t_stack **stack, char *buf)
{
	t_stack	*new;
	t_stack	*last;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	last = get_last_stack(*stack);
	if (!last)
		*stack = new;
	else
		last->next = new;
	new->buf = buf;
	new->next = NULL;
}

void	stack_next_line(int fd, t_stack **stack)
{
	int		char_read;
	char	*buf;

	while (!str_has_line_break(*stack))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buf);
			return ;
		}
		buf[char_read] = 0;
		append_to_stack(stack, buf);
	}
}

char	*read_line(t_stack *stack)
{
	int		line_len;
	char	*line;

	line_len = get_line_len(stack);
	if (line_len == 0)
		return (NULL);
	line = malloc(line_len + 1);
	if (!line)
		return (NULL);
	copy_str_line(stack, line);
	return (line);
}

void	clean_stack(t_stack **stack)
{
	t_stack		*tmp;
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
	*stack = malloc(sizeof(t_stack));
	if (!*stack)
		return ;
	(*stack)->buf = buf;
	(*stack)->next = NULL;
}

char	*get_next_line(int fd)
{
	static t_stack		*stack;
	char				*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	stack_next_line(fd, &stack);
	if (!stack)
		return (NULL);
	next_line = read_line(stack);
	clean_stack(&stack);
	return (next_line);
}
