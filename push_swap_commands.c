#include "push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	t_stack		*current;

	current = stack;
	if (stack == NULL)
		return ;
	while (current->next != stack && current->next)
	{
		printf("{index [%d] : value [%d]}\n", current->index, current->value);
		current = current->next;
	}
	printf("{index [%d] : value [%d]}\n", current->index, current->value);
}

char	*ft_read_command(void)
{
	static char		buff[32];
	int				r;

	ft_bzero(buff, 32);
	r = read(0, buff, 31);
	if (r > 1)
		buff[r - 1] = '\0';
	else
		return ("");
	return (buff);
}

void	ft_init_commands(t_command *commands)
{
	commands[0].name = "sa";
	commands[0].func = ft_sa;
	commands[1].name = "sb";
	commands[1].func = ft_sb;
	commands[2].name = "ss";
	commands[2].func = ft_ss;
	commands[3].name = "pa";
	commands[3].func = ft_pa;
	commands[4].name = "pb";
	commands[4].func = ft_pb;
	commands[5].name = "ra";
	commands[5].func = ft_ra;
	commands[6].name = "rb";
	commands[6].func = ft_rb;
	commands[7].name = "rr";
	commands[7].func = &ft_rr;
	commands[8].name = "rra";
	commands[8].func = &ft_rra;
	commands[9].name = "rrb";
	commands[9].func = &ft_rrb;
	commands[10].name = "rrr";
	commands[10].func = &ft_rrr;
	commands[11].name = NULL;
}

int	ft_execute(char *c, t_stack **a, t_stack **b, t_command *comms)
{
	int			i;
	static int	cnt;

	i = 0;
	while ((comms + i)->name)
	{
		if (ft_strncmp(c, comms[i].name, ft_strlen(c) + 1) == 0)
		{
			comms[i].func(a, b);

			// printf("stack a\n");
			//printf("disorder value [%d]\n", ft_compute_disorder(*a));
			// ft_print_stack(*a);
			// printf("stack b\n");
			// printf("\n");
			//printf("disorder value [%d]\n", ft_compute_disorder(*b));
			// ft_print_stack(*b);
			printf("%s\n", comms[i].name);
			// printf("\n");
			cnt += 1;
			printf("Miau, blyat' %d\n", cnt);
			return (cnt);
		}
		i++;
	}
	return (cnt);
}
