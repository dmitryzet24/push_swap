#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i <= nb / i) /* No point in continuing */
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i - 1); /* Bc we have to have actual number on return */
}

/* Finds best position for a current number have to be sorted */
int	ft_find_best_pos(t_stack *s, int current_chank_limit)
{
	t_stack		*tmp;
	int			pos;
	int			top_match_pos;
	int			bottom_match_pos;

	if (!s)
		return (-1);
	top_match_pos = -1;
	bottom_match_pos = -1;
	tmp = s;
	pos = 0;
	while (tmp)
	{
		if (tmp->index <= current_chank_limit)
		{
			if (top_match_pos == -1)
				top_match_pos = pos;
			bottom_match_pos = pos;
		}
		pos++;
		tmp = tmp->next;
		if (tmp == s)
			break;
	}
	if (top_match_pos == -1)
		return (-1);
	if (top_match_pos <= (pos - bottom_match_pos))
		return (top_match_pos);
	return (bottom_match_pos);
}

/* We should have index in t_stack a ALREADY */
void	ft_chunk_sort(t_stack **a, t_stack **b, t_command *comms)
{
	size_t		stack_len;
	int			chank_size;
	int			current_chank_limit;
	int			target_pos;
	int			rotations;

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
	
}
