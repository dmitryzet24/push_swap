/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsutormi <dsutormi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:52:39 by dsutormi          #+#    #+#             */
/*   Updated: 2026/05/12 14:11:53 by dsutormi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_read_command(void)
{
	static char		buff[32];
	int				r;

	ft_bzero(buff, 32);
	r = read(0, buff, 31);
	if (r > 1)
		buff[r - 1] = '\0';
	else
		return (NULL);
	return (buff);
}

t_stack	*ft_stack_rotate(t_stack *stack)
{
	
}
t_stack	*ft_swap_stack(t_stack *stack)
{
	t_stack		*second;
	t_stack		*last;

	if (stack && (ft_stack_len(stack) > 2))
	{
		last = stack->prev;
		second = stack->next;
		stack->next = second->next;
		second->prev = last;
		stack->prev = second;
		second->next = stack;
		last->next = second;
		stack->next->prev = stack;
		return (second);
	}
	else if (stack && (ft_stack_len(stack) == 2))
	{
		
	}
	return (stack);
}
