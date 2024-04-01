/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:56:49 by idel-poz          #+#    #+#             */
/*   Updated: 2024/04/01 15:24:05 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	stack_next_line(int fd, str_stack **stack)
{
	int		char_read;
	char	*buf;

	while (!str_has_line_break(*stack))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buf);
			return;
		}
		buf[char_read] = 0;
		append_to_stack(stack, buf);
	}
}

int	str_has_line_break(str_stack *stack)
{
	int i;

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

void	append_to_stack(str_stack **stack, char *buf)
{
	str_stack	*new;
	str_stack	*last;

	new = malloc(sizeof(str_stack));
	if (!new)
		return;
	last = get_last_stack(*stack);
	if (!last)
		*stack = new;
	else
		last->next = new;
	new->buf = buf;
	new->next = NULL;
}

int	get_line_len(str_stack *stack)
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

char	*copy_str_line(str_stack *stack, char *line)
{
	int		i;
	int		j;

	i = 0;
	while (stack)
	{
		j = 0;
		while (stack->buf[j] && stack->buf[j] != '\n')
		{
			line[i] = stack->buf[j];
			i++;
			j++;
		}
		stack = stack->next;
	}
	line[i] = 0;
	return (line);
}

char	*read_line(str_stack *stack)
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

void	clean_stack(str_stack **stack)
{
	str_stack	*tmp;
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
		return;
	*stack = malloc(sizeof(str_stack));
	if (!*stack)
		return;
	(*stack)->buf = buf;
	(*stack)->next = NULL;
}

str_stack	*get_last_stack(str_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

char	*get_remaining_buffer(str_stack **stack)
{
	str_stack	*last;
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
	if (str_len(buf) == 0)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}