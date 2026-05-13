/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_3_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsutormi <dsutormi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:08:39 by dsutormi          #+#    #+#             */
/*   Updated: 2026/05/13 12:15:35 by dsutormi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack **a, t_stack **b)
{
	ft_stack_rev_rotate(a, b);
}

void	ft_rrb(t_stack **a, t_stack **b)
{
	ft_stack_rev_rotate(b, a);
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_stack_rev_rotate(a, b);
	ft_stack_rev_rotate(b, a);
}
