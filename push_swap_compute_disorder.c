/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_compute_disorder.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsutormi <dsutormi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:34:11 by dandrush          #+#    #+#             */
/*   Updated: 2026/05/20 16:49:45 by dsutormi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_compute_disorder(t_stack *n)
{
	int		mistakes;
	int		total_pairs;
	size_t	len;
	t_stack	*i;
	t_stack	*j;

	mistakes = 0;
	total_pairs = 0;
	i = n;
	len = ft_stack_len(n);
	if (n == NULL)
		return (10000);
	if (len == 1)
		return (10000);
	while (i != n->prev)
	{
		j = i;
		while (j != n->prev)
		{
			j = j->next;
			total_pairs += 1;
			if (i->value > j->value)
				mistakes += 1;
		}
		i = i-> next;
	}
	return (((mistakes * 10000) / total_pairs));
}
