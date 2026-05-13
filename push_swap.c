/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsutormi <dsutormi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 20:32:19 by dsutormi          #+#    #+#             */
/*   Updated: 2026/05/13 13:37:43 by dsutormi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int				i;
	t_stack			*stack_a;
	t_stack			*stack_b;
	char			*command;
	t_command		commands[12];

	if (argc < 2)
		return (0);
	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	ft_init_commands(&commands);//, &stack_a, &stack_b);
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
			// ft_stack_swap(&stack_a, &stack_b);
			commands[SA].func(&stack_a, &stack_b);
			printf("stack a\n");
			ft_print_stack(stack_a);
			printf("stack b\n");
			ft_print_stack(stack_b);
			command = NULL;
		}
		else if (*command == 'r')
		{
			ft_stack_rotate(&stack_a, &stack_b);
			printf("stack a\n");
			ft_print_stack(stack_a);
			printf("stack b\n");
			ft_print_stack(stack_b);
			command = NULL;
		}
		else if (*command == 'p')
		{
			ft_stack_push(&stack_b, &stack_a);
			printf("stack a\n");
			ft_print_stack(stack_a);
			printf("stack b\n");
			ft_print_stack(stack_b);
			command = NULL;
		}
		command = ft_read_command();
	}
	if (stack_a)
		ft_free_stack(stack_a);
	if (stack_b)
		ft_free_stack(stack_b);
	return (0);
}
