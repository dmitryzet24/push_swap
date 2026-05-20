
#include "push_swap.h"

int	ft_check_input(int argc, char **argv)
{

}

int	ft_init_stucture(t_stack **a, t_stack **b, int argc, char **argv)
{
	if (argc > 501)
		return (0);
	if (argc == 2)
	i = 1;
	stack_a = NULL;
	stack_b = NULL;

	
	while (i < argc)
	{
		ft_stackadd_back(&stack_a, ft_stacknew(ft_atoi(argv[i]), i - 1));
		i++;
	}
}