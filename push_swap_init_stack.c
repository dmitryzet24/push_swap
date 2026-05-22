#include "push_swap.h"

int	ft_check_doubles(int argc, char **argv, int (*arr)[512])
{
	int		i;

	i = 1;
	while (i < argc)
	{
		(*arr)[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	ft_shell_sort(*arr, argc - 1);
	i = 0;
	while (i < argc - 2)
	{
		if ((*arr)[i] == (*arr)[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_input(int argc, char **argv, int (*arr)[512])
{
	int		i;
	int		j;

	if (argc < 2 || argc > 501)
		return (0);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j]) || (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]))))
				return (0);
			j++;
		}
		i++;
	}
	if (ft_check_doubles(argc, argv, arr))
		return (0);
	return (1);
}
int ft_get_index2(int *arr, int val)
{
	int i;
	i = 0;
	
	while (val != arr[i])
		i++;
	
	return (i);
}

int	ft_return_strategy(int *argc, char **argv)
{
	int		strategy;

	strategy = 4;
	if (ft_strncmp(argv[*argc-1], "--simple", 9) == 0)
	{
		printf("simple\n");
		(*argc)--;
		strategy = 1;
	}
	else if (ft_strncmp(argv[*argc-1], "--medium", 9) == 0)
	{
		printf("medium\n");
		(*argc)--;
		strategy = 2;
	}
	else if (ft_strncmp(argv[*argc-1], "--complex", 10) == 0)
	{
		printf("complex\n");
		(*argc)--;
		strategy = 3;
	}
	else if (ft_strncmp(argv[*argc-1], "--adaptive", 11) == 0)
	{
		printf("adaptive\n");
		(*argc)--;
	}
	return (strategy);
}

int	ft_init_stucture(t_stack **a, t_stack **b, int argc, char **argv)
{
	int		value;
	int		i;
	t_stack	*node;
	int		arr[512];
	int		strategy;

	strategy = ft_return_strategy(&argc, argv);
	if (ft_strncmp(argv[argc-1], "--simple", 9) == 0)
		printf("simple\n");
		// strategy = 1;
	if (ft_strncmp(argv[argc-1], "--medium", 9) == 0)
		printf("medium\n");
		// strategy = 2;
	if (ft_strncmp(argv[argc-1], "--complex", 10) == 0)
		printf("complex\n");
		// strategy = 3;
	if (ft_strncmp(argv[argc-1], "--adaptive", 11) == 0)
		printf("adaptive\n");
	// argc--;
	
	if (!(ft_check_input(argc, argv, &arr)))
		return (0);
	*a = NULL;
	*b = NULL;
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		node = ft_stacknew(value, ft_get_index2(arr, value));
		ft_stackadd_back(a, node);
		i++;
	}
	return (strategy);
}
