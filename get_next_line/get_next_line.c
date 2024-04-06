/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:56:54 by idel-poz          #+#    #+#             */
/*   Updated: 2024/04/06 16:42:54 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	copy_str_line(t_str_stack *stack, char *line)
{
	int		i;
	int		j;

	i = 0;
	while (stack)
	{
		j = 0;
		while (stack->buf[j])
		{
			if (stack->buf[j] == '\n')
			{
				line[i++] = '\n';
				line[i] = 0;
				return ;
			}
			line[i] = stack->buf[j];
			i++;
			j++;
		}
		stack = stack->next;
	}
	line[i] = 0;
}

void	stack_next_line(int fd, t_str_stack **stack)
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

void	append_to_stack(t_str_stack **stack, char *buf)
{
	t_str_stack	*new;
	t_str_stack	*last;

	new = malloc(sizeof(t_str_stack));
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

char	*read_line(t_str_stack *stack)
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

char	*get_next_line(int fd)
{
	static t_str_stack	*stack;
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
