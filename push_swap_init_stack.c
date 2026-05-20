#include "push_swap.h"

int	ft_check_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!(ft_isdigit(line[i]) || line[i] == '-'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_doubles(int argc, char **argv, int (*arr)[512])
{
	int		i;
	// int		arr[512];

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
	// i = 0;
	// while (i < argc -1)
	// {
	// 	(*arr)[i] = i;
	// 	i++;
	// }
	return (0);
}

int	ft_check_input(int argc, char **argv, int (*arr)[512])
{
	int		i;

	if (argc < 2 || argc > 501)
		return (1);
	i = 1;
	while (i < argc)
	{
		if (ft_check_line(argv[i]))
			return (1);
		i++;
	}
	if (ft_check_doubles(argc, argv, arr))
		return (1);
	return (0);
}
int ft_get_index2(int *arr, int val)
{
	int i;
	i = 0;
	
	while (val != arr[i])
		i++;
	
	return (i);
}
int	ft_init_stucture(t_stack **a, t_stack **b, int argc, char **argv)
{
	int		value;
	int		i;
	t_stack	*node;
	int		arr[512];


	if (ft_check_input(argc, argv, &arr))
		return (1);
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
	return (0);
}
