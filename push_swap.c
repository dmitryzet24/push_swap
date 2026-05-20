#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	char			*command;
	t_command		commands[12];

	ft_init_commands(commands);
	if (ft_init_stucture(&stack_a, &stack_b, argc, argv))
		return (0);
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
