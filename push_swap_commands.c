/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsutormi <dsutormi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:05:30 by dsutormi          #+#    #+#             */
/*   Updated: 2026/05/12 17:05:47 by dsutormi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	t_stack		*current;

	current = stack;
	if (stack == NULL)
		return ;
	while (current->next != stack && current->next)
	{
		printf("{index [%d] : value [%d]}\n", current->index, current->value);
		current = current->next;
	}
	printf("{index [%d] : value [%d]}\n", current->index, current->value);
}

char	*ft_read_command(void)
{
	static char		buff[32];
	int				r;

	ft_bzero(buff, 32);
	r = read(0, buff, 31);
	if (r > 1)
		buff[r - 1] = '\0';
	else
		return (NULL);
	return (buff);
}
