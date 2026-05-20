/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_insertion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsutormi <dsutormi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:47:38 by dsutormi          #+#    #+#             */
/*   Updated: 2026/05/20 15:33:11 by dsutormi         ###   ########.fr       */
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

void	ft_fill_stack_a(t_stack **a, t_stack **b, t_command *commands)
{
	while (ft_compute_disorder(*b) != 10000)
		ft_execute("rb", a, b, commands);
	while (*b)
		ft_execute("pa", a, b, commands);
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
			while ((*a)->value < (*b)->value)
				ft_execute("rb", a, b, commands);
			continue ;
		}
		if ((*a && (*a)->value > (*b)->value) && ((*a)->value < max))
		{
			while ((*a)->value > (*b)->prev->value)
				ft_execute("rb", a, b, commands);
			continue ;
		}
		while (ft_compute_disorder(*b) != 10000)
			ft_execute("rb", a, b, commands);
		ft_update_maxmin(&max, &min, a);
	}
	ft_fill_stack_a(a, b, commands);
}
