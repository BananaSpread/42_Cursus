/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:56:49 by idel-poz          #+#    #+#             */
/*   Updated: 2024/09/21 12:57:12 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_has_line_break(t_stack *stack)
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

int	get_line_len(t_stack *stack)
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

char	*copy_str_line(t_stack *stack, char *line)
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

t_stack	*get_last_stack(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

char	*get_remaining_buffer(t_stack **stack)
{
	t_stack	*last;
	char	*buf;
	int		i;
	int		j;

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
	if (ft_strlen(buf) == 0)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}
