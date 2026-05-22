/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_insertion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsutormi <dsutormi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:47:38 by dsutormi          #+#    #+#             */
/*   Updated: 2026/05/22 13:22:12 by dsutormi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_update_maxmin(int *max, int *min, t_stack **a)
{
	if (*a == NULL)
		return ;
	if ((*a)->value > *max)
		*max = (*a)->value;
	if ((*a)->value < *min)
		*min = ((*a)->value);
}

void	ft_sort_by_disorder(t_stack **a, t_stack **b, t_command *commands)
{
	int		count_r;
	int		count_rr;
	t_stack	*temp;

	count_r = 0;
	count_rr = 0;
	temp = *b;
	while (ft_compute_disorder(temp) != 10000)
	{
		temp = temp->next;
		count_r++;
	}
	temp = *b;
	while (ft_compute_disorder(temp) != 10000)
	{
		temp = temp->prev;
		count_rr++;
	}
	if (count_r <= count_rr)
	{
		while (ft_compute_disorder(*b) != 10000)
			ft_execute("rb", a, b, commands);
		return ;
	}
	while (ft_compute_disorder(*b) != 10000)
		ft_execute("rrb", a, b, commands);
}

void	ft_rotate_handler_more_min(t_stack **a, t_stack **b, t_command *commands)
{
	int		count_r;
	int		count_rr;
	t_stack	*temp;

	count_r = 0;
	count_rr = 0;
	temp = *b;
	while ((*a)->value < temp->value)
	{
		temp = temp->next;
		count_r++;
	}
	temp = *b;
	while ((*a)->value < temp->value)
	{
		temp = temp->prev;
		count_rr++;
	}
	if (count_r <= count_rr)
	{
		while ((*a)->value < (*b)->value)
			ft_execute("rb", a, b, commands);
		return ;
	}
	while ((*a)->value < (*b)->value)
			ft_execute("rrb", a, b, commands);
}

void	ft_rotate_handler_less_max(t_stack **a, t_stack **b, t_command *commands)
{
	int		count_r;
	int		count_rr;
	t_stack	*temp;

	count_r = 0;
	count_rr = 0;
	temp = *b;
	while ((*a)->value > temp->prev->value)
	{
		temp = temp->next;
		count_r++;
	}
	temp = *b;
	while ((*a)->value > temp->prev->value)
	{
		temp = temp->prev;
		count_rr++;
	}
	if (count_r <= count_rr)
	{
		while ((*a)->value > (*b)->prev->value)

			ft_execute("rb", a, b, commands);
		return ;
	}
	while ((*a)->value > (*b)->prev->value)
			ft_execute("rrb", a, b, commands);
}

void	ft_insertion_sort(t_stack **a, t_stack **b, t_command *commands)
{
	int			max;
	int			min;

	max = (*a)->value;
	min = (*a)->value;
	while (*a)
	{
		ft_execute("pb", a, b, commands);
		if (*a && ((*a)->value < (*b)->value) && ((*a)->value > min))
		{
			ft_rotate_handler_more_min(a, b, commands);
			continue ;
		}
		if ((*a && (*a)->value > (*b)->value) && ((*a)->value < max))
		{
			ft_rotate_handler_less_max(a, b, commands);
			continue ;
		}
		ft_sort_by_disorder(a, b, commands);
		ft_update_maxmin(&max, &min, a);
	}
	ft_sort_by_disorder(a, b, commands);
	while (*b)
		ft_execute("pa", a, b, commands);
}
