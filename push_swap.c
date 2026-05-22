#include "push_swap.h"
/*
An optional strategy selector:
--simple Forces the use of your O(n2) algorithm. ft_init_structure return 1
--medium Forces the use of your O(n√n) algorithm. ft_init_structure return 2
--complex Forces the use of your O(n log n) algorithm. ft_init_structure return 3
--adaptive F ft_init_structure return 4
*/
int	main(int argc, char **argv)
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	char			*command;
	t_command		commands[12];
	int				strategy;

	ft_init_commands(commands);
	strategy = ft_init_stucture(&stack_a, &stack_b, argc, argv);
	if (!strategy)
		return (0);

	ft_print_stack(stack_a);
	if (strategy == 1)
		ft_insertion_sort(&stack_a, &stack_b, commands);
	else if (strategy == 2)
		ft_chunk_sort(&stack_a, &stack_b, commands);
	else if (strategy == 4)
		ft_insertion_sort(&stack_a, &stack_b, commands);
	ft_print_stack(stack_a);
	command = ft_read_command();
	while (ft_strncmp(command, "q", ft_strlen(command) + 1) != 0)
	{
		ft_execute(command, &stack_a, &stack_b, commands);
		command = ft_read_command();
	}
	if (stack_a)
		ft_free_stack(stack_a);
	if (stack_b)
		ft_free_stack(stack_b);
	return (0);
}
