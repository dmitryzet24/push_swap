/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsutormi <dsutormi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:52:39 by dsutormi          #+#    #+#             */
/*   Updated: 2026/05/13 14:15:20 by dsutormi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_rotate(t_stack **stack, t_stack **unused)
{
	(void)unused;
	if (stack == NULL)
		return ;
	if (*stack)
		*stack = (*stack)->next;
}

void	ft_stack_rev_rotate(t_stack **stack, t_stack **unused)
{
	(void)unused;
	if (stack == NULL)
		return ;
	if (*stack)
		*stack = (*stack)->prev;
}

t_stack	*ft_stack_del_top(t_stack *stack)
{
	t_stack		*new_top;
	t_stack		*last;

	if (ft_stack_len(stack) > 1)
	{
		last = stack->prev;
		new_top = stack->next;
		new_top->prev = last;
		last->next = new_top;
		free(stack);
	}
	else
		return (free(stack), NULL);
	return (new_top);
}

void	ft_stack_push(t_stack **dest, t_stack **src)
{
	if (dest == NULL || src == NULL)
		return ;
	if (*src == NULL)
		return ;
	ft_stackadd_front(dest, ft_stacknew((*src)->value, (*src)->index));
	*src = ft_stack_del_top(*src);
}

void	ft_stack_swap(t_stack **stack, t_stack **unused)
{
	t_stack		*second;
	t_stack		*last;

	(void)(unused);
	if (stack == NULL)
		return ;
	if (*stack == NULL)
		return ;
	if (*stack && (ft_stack_len(*stack) > 2))
	{
		last = (*stack)->prev;
		second = (*stack)->next;
		(*stack)->next = second->next;
		second->prev = last;
		(*stack)->prev = second;
		second->next = *stack;
		last->next = second;
		(*stack)->next->prev = *stack;
		*stack = second;
	}
	else if (*stack && (ft_stack_len(*stack) == 2))
		ft_stack_rotate(stack, unused);
}
