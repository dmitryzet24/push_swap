/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_1_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsutormi <dsutormi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 11:54:38 by dsutormi          #+#    #+#             */
/*   Updated: 2026/05/13 12:15:12 by dsutormi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **a, t_stack **b)
{
	ft_stack_swap(a, b);
}

void	ft_sb(t_stack **a, t_stack **b)
{
	ft_stack_swap(b, a);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_stack_swap(a, b);
	ft_stack_swap(b, a);
}

void	ft_pa(t_stack **a, t_stack **b)
{
	ft_stack_push(a, b);
}

void	ft_pb(t_stack **a, t_stack **b)
{
	ft_stack_push(b, a);
}
