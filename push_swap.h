/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsutormi <dsutormi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:04:43 by dsutormi          #+#    #+#             */
/*   Updated: 2026/05/12 15:18:31 by dsutormi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int					value;
	int					index;

	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

t_stack		*ft_stacknew(int content, int index);
void		ft_stackadd_back(t_stack **stack, t_stack *new);
void		ft_print_stack(t_stack *stack);
void		ft_free_stack(t_stack *stack);
char		*ft_read_command(void);
t_stack		*ft_swap_stack(t_stack *stack);
size_t		ft_stack_len(t_stack *stack);
void		ft_stackadd_front(t_stack **stack, t_stack *new);
t_stack		*ft_stack_rotate(t_stack *stack);
t_stack		*ft_stack_rev_rotate(t_stack *stack);

#endif