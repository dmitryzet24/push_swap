/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsutormi <dsutormi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 18:24:44 by dsutormi          #+#    #+#             */
/*   Updated: 2026/05/13 12:33:37 by dsutormi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int value, int index)
{
	t_stack		*new;

	new = malloc(sizeof(t_stack) * 1);
	if (new == NULL)
		return (NULL);
	new->value = value;
	new->index = index;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack		*last;

	if (stack == NULL || new == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	last = (*stack)->prev;
	last->next = new;
	new->prev = last;
	new->next = *stack;
	(*stack)->prev = new;
}

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	ft_stackadd_back(stack, new);
	ft_stack_rev_rotate(stack, NULL);
}

void	ft_free_stack(t_stack *stack)
{
	t_stack		*current;
	t_stack		*temp;

	current = stack;
	while (current->next != stack && current->next)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	free(current);
}

size_t	ft_stack_len(t_stack *stack)
{
	size_t		i;
	t_stack		*first;

	first = stack;
	i = 0;
	if (stack == NULL)
		return (0);
	while (stack->next != first)
	{
		stack = stack->next;
		i++;
	}
	return (++i);
}
