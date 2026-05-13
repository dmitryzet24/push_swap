/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dandrush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:34:11 by dandrush          #+#    #+#             */
/*   Updated: 2026/05/13 16:35:10 by dandrush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "push_swap.h"*/
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
typedef	struct s_stack
{
	int	value;

	struct	s_stack	*next;
	struct	s_stack *prev;
}	t_stack;


size_t	t_stacklen(t_stack *n)
{
	size_t	i;
	t_stack	*start;

	
	i = 1;
	start = n;
	while (n->next != start && n != NULL)
	{
		i++;
		n = n->next;
	}
	return (i);
}

int	compute_disorder(t_stack *n)
{
	int		mistakes;
	int		total_pairs;
	size_t	len;
	t_stack	*i;
	t_stack	*j;

	mistakes = 0;
	total_pairs = 0;
	i = n;
	len = t_stacklen(n);
	while (i != n->prev)
	{
		j = i;
		while (j != n->prev)
		{
			j = j->next;
			total_pairs += 1;
			if (i->value  > j->value)
				mistakes += 1;
		}
		i = i->next;
	}	
	return ((mistakes/total_pairs)*1000);
}


int main(void)
{
	t_stack	*a;
printf("%s\n", "Adding New node to the Back");
	a = newnode(2);
	printf("%s\n", "Filling Up first node");
	printf("%d\n", a->value);
	printf("%p\n", a->next);
	printf("%p\n", a->prev);
	addback_node(a, 3);
	printf("%s\n", "Adding New node to the Back");
	a = a->next;
	printf("%d\n", a->value);
    printf("%p\n", a->next);
    printf("%p\n", a->prev);
	printf("%p\n", a);
	addback_node(a, 4);
	printf("%s\n", "Adding New node to the Back");
	a = a->next;
	printf("%d\n", a->value);
	printf("%p\n", a->next);
	printf("%p\n", a->prev);
	printf("%s\n", "Computing Disorder...")
	print("%d", compute_disorder(a));
	return (0);
}

