/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsutormi <dsutormi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 20:32:19 by dsutormi          #+#    #+#             */
/*   Updated: 2026/05/12 14:07:30 by dsutormi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;
	char	*command;

	if (argc < 2)
		return (0);
	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		ft_stackadd_back(&stack_a, ft_stacknew(ft_atoi(argv[i]), i - 1));
		i++;
	}
	ft_print_stack(stack_a);
	command = ft_read_command();
	while (command)
	{
		if (*command == 'a')
		{
			stack_a = ft_swap_stack(stack_a);
			ft_print_stack(stack_a);
			command = NULL;
		}
		command = ft_read_command();
	}
	ft_free_stack(stack_a);
	return (0);
}
