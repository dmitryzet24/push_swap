/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsutormi <dsutormi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:04:43 by dsutormi          #+#    #+#             */
/*   Updated: 2026/05/12 17:14:37 by dsutormi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

# define SA 0x01
# define SB 0x02
# define SS 0x03
# define PA 0x04
# define PB 0x05
# define RA 0x06
# define RB 0x07
# define RR 0x08
# define RRA 0x09
# define RRB 0x0a
# define RRR 0x0b

typedef struct s_stack
{
	int					value;
	int					index;

	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

// typedef struct s_single_command
// {
// 	char	*name;
// 	int		code:
// 	void	*addr;
// }	t_single_command;

// typedef struct s_list_commands
// {
// 	t_single_command	command;
// }	t_list_commands;

char		*ft_read_command(void);
size_t		ft_stack_len(t_stack *stack);
void		ft_stackadd_back(t_stack **stack, t_stack *new);
void		ft_print_stack(t_stack *stack);
void		ft_free_stack(t_stack *stack);
void		ft_stack_swap(t_stack **stack, t_stack **unused);
void		ft_stackadd_front(t_stack **stack, t_stack *new);
void		ft_stack_rotate(t_stack **stack);
void		ft_stack_rev_rotate(t_stack **stack);
void		ft_stack_push(t_stack **dest, t_stack **src);
t_stack		*ft_stack_del_top(t_stack *stack);
t_stack		*ft_stacknew(int content, int index);

#endif