#include "push_swap.h"

/* Checks for duplicated digits in an Unsorted int array */
int	ft_check_doubles(int argc, char **argv, int (*arr)[3])
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

/* Checks input string for -- and non-digit chars */
int	ft_check_input(int argc, char **argv, int (*arr)[3])
{
	int		i;
	int		j;
	int		flag;

	if (argc < 2 || argc > 3)
		return (0);
	i = 1;
	while (i < argc)
	{
		flag = 1;
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '-') && flag--)
				j++;
			if (!(ft_isdigit(argv[i][j])))
				return (0);
			j++;
		}
		i++;
	}
	if (ft_check_doubles(argc, argv, arr))
		return (0);
	return (1);
}

/*Serches for a Value in a given Array and returns its Index */
int	ft_get_index2(int *arr, int val)
{
	int		i;

	i = 0;
	while (val != arr[i])
		i++;
	return (i);
}

/* Looks for a Strategy flag in the first argv */
int	ft_return_strategy(int *argc, char **argv)
{
	if (ft_strncmp(argv[1], "--simple", 9) == 0)
		return (1);
	else if (ft_strncmp(argv[1], "--medium", 9) == 0)
		return (2);
	else if (ft_strncmp(argv[1], "--complex", 10) == 0)
		return (3);
	else if (ft_strncmp(argv[1], "--adaptive", 11) == 0)
		return (4);
}

/* Creates doudle-linked cycled list from the input string */
int	ft_init_stucture(t_stack **a, t_stack **b, int argc, char **argv)
{
	int		value;
	int		i;
	t_stack	*node;
	int		arr[3];
	int		strategy;

	strategy = ft_return_strategy(&argc, argv);
	if (!(ft_check_input(argc, argv, &arr)))
		return (0);
	*a = NULL;
	*b = NULL;
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		node = ft_stacknew(value, ft_get_index2(arr, value));
		if (node == NULL && *a != NULL)
			ft_free_stack(*a)
		ft_stackadd_back(a, node);
		i++;
	}
	return (strategy);
}
