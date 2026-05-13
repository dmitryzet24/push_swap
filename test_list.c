# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
typedef	struct s_stack
{
	int	value;

	struct	s_stack	*next;
	struct	s_stack *prev;
}	t_stack;

t_stack	*newnode(int value)
{
	t_stack *new;
	
	new = malloc(sizeof(t_stack));
	if (!new)
		return NULL;
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	addback_node(t_stack *original, int value)
{
	t_stack	*last;

	if (original == NULL)
	{
		original = newnode(value);
		return ;
	}
	last = newnode(value);
	last->prev = original;
	original->next = last;
}
/*
int main(void)
{
	t_stack	*a;

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
	return (0);
}
*/
