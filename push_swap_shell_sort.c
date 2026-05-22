#include "push_swap.h"

/*Shell Sotr function using Lazarus & Frank sequence*/
void	ft_shell_sort(int *arr, int n)
{
	int	gap;
	int	i;
	int	j;
	int	temp;

	j = 0;
	if (n < 1 || !arr)
		return ;
	gap = 1;
	while (gap < n)
		gap = ((gap * 2) + 1);
	gap = ((gap - 1) / 2);
	while (gap > 0)
	{
		i = gap;
		while (i < n)
		{
			temp = arr[i];
			j = i;
			while (j >= gap && arr[j - gap] > temp)
			{
				arr[j] = arr[j - gap];
				j -= gap;
			}
			arr[j] = temp;
			i++;
		}
		gap = ((gap - 1) / 2);
	}
}

// int	*ft_list_to_arr(t_stack *a)
// {
// 	size_t	stln;
// 	size_t		j;
// 	int		*arr;

// 	stln = ft_stack_len(a);
// 	arr = malloc(sizeof(int) * stln);
// 	if (!arr)
// 		return NULL;
// 	j = 0;
// 	while (j < stln)
// 	{
// 		arr[j] = a->value;
// 		j++;
// 		a = a->next;
// 	}
// 	return (arr);
// }

// int	ft_get_index(int value, int *arr, int size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		if (arr[i] == value)
// 			return i;
// 		i++;
// 	}
// 	return (0);
// }

// void	ft_stack_put_index(t_stack *a)
// {
// 	int		*arr;
// 	int		size;
// 	t_stack	*curr;
// 	size = ft_stack_len(a);
// 	arr = ft_list_to_arr(a);
// 	if (!arr)
// 		return ;
// 	ft_shell_sort(arr, size);
// 	curr = a;
// 	while (curr)
// 	{
// 		curr->index = ft_get_index(curr->value, arr, size);
// 		curr = curr->next;
// 	}
// 	free(arr);
// }


/*
int main(void)
{
	int arr[] = {65, 34, 21, 100, 2, 45, 8, 12, 0, -5};
	int n = sizeof(arr) / sizeof(arr[0]);	
	printf("Исходный массив:\n");
	for (int i = 0; i < n; i++)
	    printf("%d ", arr[i]);
	printf("\n\n");	

	shell_sort(arr, n);	
	printf("Отсортированный массив:\n");
	for (int i = 0; i < n; i++)
	    printf("%d ", arr[i]);
	printf("\n");	
	return (0);
}
*/