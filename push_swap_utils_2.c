/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsutormi <dsutormi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:52:39 by dsutormi          #+#    #+#             */
/*   Updated: 2026/05/12 15:20:03 by dsutormi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_rotate(t_stack *stack)
{
	return (stack->next);
}

t_stack	*ft_stack_rev_rotate(t_stack *stack)
{
	return (stack->prev);
}

// void	ft_stack_push(t_stack **dest, t_stack **src)
// {

	
// }
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
		stack = ft_stack_rotate(stack);
	return (stack);
}
