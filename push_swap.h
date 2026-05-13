/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dandrush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:53:23 by dandrush          #+#    #+#             */
/*   Updated: 2026/05/13 18:16:23 by dandrush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

# define SA 0x00
# define SB 0x01
# define SS 0x02
# define PA 0x03
# define PB 0x04
# define RA 0x05
# define RB 0x06
# define RR 0x07
# define RRA 0x08
# define RRB 0x09
# define RRR 0x0a

typedef struct s_stack
{
	int					value;
	int					index;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

typedef void (t_operation)(t_stack **a, t_stack **b);

typedef struct s_command
{
	char					*name;
	t_operation				*func;
}	t_command;

char		*ft_read_command(void);
size_t		ft_stack_len(t_stack *stack);
void		ft_stackadd_back(t_stack **stack, t_stack *new);
void		ft_print_stack(t_stack *stack);
void		ft_free_stack(t_stack *stack);
void		ft_stack_swap(t_stack **stack, t_stack **unused);
void		ft_stackadd_front(t_stack **stack, t_stack *new);
void		ft_stack_rotate(t_stack **stack, t_stack **unused);
void		ft_stack_rev_rotate(t_stack **stack, t_stack **unused);
void		ft_stack_push(t_stack **dest, t_stack **src);
t_stack		*ft_stack_del_top(t_stack *stack);
t_stack		*ft_stacknew(int content, int index);
void		ft_init_commands(t_command (*comm));//, t_stack **a, t_stack **b);
void		ft_execute(char *c, t_stack **a, t_stack **b, t_command *comms);
void		ft_sa(t_stack **a, t_stack **b);
void		ft_sb(t_stack **a, t_stack **b);
void		ft_ss(t_stack **a, t_stack **b);
void		ft_pa(t_stack **a, t_stack **b);
void		ft_pb(t_stack **a, t_stack **b);
void		ft_ra(t_stack **a, t_stack **b);
void		ft_rb(t_stack **a, t_stack **b);
void		ft_rr(t_stack **a, t_stack **b);
void		ft_rra(t_stack **a, t_stack **b);
void		ft_rrb(t_stack **a, t_stack **b);
void		ft_rrr(t_stack **a, t_stack **b);
int			ft_compute_disorder(t_stack *n);

#endif
