#include "push_swap.h"
#include "push_swap_2.h"

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
	if (top_match_pos <= (pos - bottom_match_pos)) return (top_match_pos);
		return (bottom_match_pos);
}

int	ft_find_index_pos(t_stack *b, int target_index)
{
	int		pos;
	t_stack	*tmp;

	tmp = b;
	pos = 0;
	if (!b)
		return (-1);
	while (tmp != NULL)
	{
		if (tmp->index == target_index)
		{
			return (pos);
		}
		pos++;
		tmp = tmp->next;
		if (tmp == b)
			break ;
	}
	return (-1);
}
