#include "../push_swap.h"


void ft_lstiter(t_node *node)
{
	while (node)
	{
		printf("%i\n", node->x);
		node = node->next;
	}
	
}