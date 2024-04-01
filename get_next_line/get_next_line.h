/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:56:58 by idel-poz          #+#    #+#             */
/*   Updated: 2024/04/01 15:24:29 by idel-poz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	char			*buf;
	struct s_stack	*next;
}	str_stack;

char		*get_next_line(int fd);

void		stack_next_line(int fd, str_stack **stack);
int			str_has_line_break(str_stack *stack);
void		append_to_stack(str_stack **stack, char *buf);
int			get_line_len(str_stack *stack);
char		*copy_str_line(str_stack *stack, char *line);
char		*read_line(str_stack *stack);
void		clean_stack(str_stack **stack);
str_stack	*get_last_stack(str_stack *stack);
char		*get_remaining_buffer(str_stack **stack);
int			str_len(char *str);

#endif