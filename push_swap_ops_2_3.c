/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_2_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsutormi <dsutormi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:03:24 by dsutormi          #+#    #+#             */
/*   Updated: 2026/05/13 12:15:21 by dsutormi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **a, t_stack **b)
{
	ft_stack_rotate(a, b);
}

void	ft_rb(t_stack **a, t_stack **b)
{
	ft_stack_rotate(b, a);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_stack_rotate(a, b);
	ft_stack_rotate(b, a);
}
