#include "push_swap.h"

int	main(int argc, char **argv)
{
	int				i;
	t_stack			*stack_a;
	t_stack			*stack_b;
	// char			*command;
	//t_command		commands[12];
	int				*arr;
	int				j;
	int				stack_len;

	if (argc < 2)
		return (0);
	i = 1;
	//ft_init_commands(commands);
	stack_a = NULL;
	stack_b = NULL;
	while (i < argc)
	{
		ft_stackadd_back(&stack_a, ft_stacknew(ft_atoi(argv[i]), i - 1));
		i++;
	}
	ft_print_stack(stack_a);
	/*
	command = ft_read_command();
	while (ft_strncmp(command, "q", ft_strlen(command) + 1) != 0)
	{
		ft_execute(command, &stack_a, &stack_b, commands);
		command = ft_read_command();
	}*/
	stack_len = ft_stack_len(stack_a);
	arr = list_to_arr(stack_a);
	if (!arr && stack_a)
	{
		ft_free_stack(stack_a);
		return (1);
	}
	shell_sort(arr, stack_len);

	j = 0;
	while (j < i - 1)
	{
		printf("%d\n", arr[j]);
		j++;
	}
	if (stack_a)
		ft_free_stack(stack_a);
	if (stack_b)
		ft_free_stack(stack_b);
	return (0);
}
