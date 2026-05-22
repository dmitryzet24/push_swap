#include "push_swap.h"
#include "push_swap_2.h"

/* We should have index in t_stack a ALREADY */
void	ft_chunk_sort(t_stack **a, t_stack **b, t_command *comms)
{
	size_t	stack_len;
	int		chank_size;
	int		current_chank_limit;
	int		target_pos;
	int		rotations;
	int		target_index;
	int		b_len;

	stack_len = ft_stack_len(*a);
	chank_size = ft_sqrt(stack_len);
	if (chank_size < 1)
		chank_size = 1;
	current_chank_limit = chank_size;
	while (*a != NULL)
	{
		target_pos = ft_find_best_pos(*a, current_chank_limit);

		if (target_pos == -1)
		{
			current_chank_limit += chank_size; /* Previous chunk pre-sorted */
			continue;
		}
		if ((size_t)target_pos <= ft_stack_len(*a) / 2) /* It's cheaper to do "ra" */
		{
			while (target_pos > 0)
			{
				ft_execute("ra", a, b, comms);
				target_pos--;
			}
		}
		else 									/* It's cheaper to do "rra" */
		{
			rotations = ft_stack_len(*a) - target_pos;
			while (rotations > 0)
			{
				ft_execute("rra", a, b, comms);
				rotations--;
			}
		}
		ft_execute("pb", a, b, comms);
		if (ft_stack_len(*b) > 1 && (*b)->index < (current_chank_limit - (chank_size / 2)))
			ft_execute("rb", a, b, comms);
	}
	target_index = ft_stack_len(*b) - 1;
	while (*b != NULL)
	{
		target_pos = ft_find_index_pos(*b, target_index);
		b_len = ft_stack_len(*b);
		if (target_pos <= b_len / 2)
		{
			while (target_pos > 0)
			{
				ft_execute("rb", a, b, comms);
				target_pos--;
			}
		}
		else
		{
			rotations = b_len - target_pos;
			while (rotations > 0)
			{
				ft_execute("rrb", a, b, comms);
				rotations--;
			}
		}
		ft_execute("pa", a, b, comms);
		target_index--;
	}
}
