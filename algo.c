/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:55:36 by codespace         #+#    #+#             */
/*   Updated: 2024/07/09 10:17:42 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sorter(t_node **stack_a, t_node **stack_b)
{
	int i;
	t_node *tmp;
	int size;
	int num;

	size = ft_lstsize(*stack_b);
	i = size - 1;
	position(*stack_b);
	tmp = *stack_b;
	while (i >= 0)
	{
		set_index(*stack_b);
		tmp = *stack_b;
		// if (i >= size - 2)
		// {
		// 	printf("-----\n");
		// 	ft_lstiter(*stack_b);
		// 	printf("-----\n");
		// 	ft_lstiter(*stack_a);
		// 	printf("-----\n");
		// 	if (i == size - 2)
		// 		exit(0);
		// }
		while (tmp->pos != i)
			tmp = tmp->next;
		num = tmp->x;
		if (tmp && tmp->index + 1 <= size / 2)
		{
			while (num != (*stack_b)->x)
			{
				rotate(stack_b, 'b');
			}
		}
		else
		{
			while (num != (*stack_b)->x)
			{
				rrotate(stack_b, 'b');
			}
		}
		pa(stack_a, stack_b);
 		i--;
	}
}

void algo(t_node **stack_a, t_node **stack_b, int size)
{
	t_node *tmp;
	int	i;
	int x;

	tmp = *stack_a;
	i = 0;
	position(*stack_a);
	if (size < 100)
		x = 16;
	else
		x = 34;
	while (*stack_a)
	{
		if ((*stack_a)->pos <= i)
		{
			pb(stack_a, stack_b);
		}
		else if ((*stack_a)->pos <= x + i)
		{
			pb(stack_a, stack_b);
			rotate(stack_b, 'b');
		}
		else
		{
			rotate(stack_a, 'a');
		}
		i++;

	}
	sorter(stack_a, stack_b);
}

void starter(t_node **stack_a, t_node **stack_b)
{
	int size;

	size = ft_lstsize(*stack_a);
	if (sorted_checker(*stack_a))
		return ;
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if ((*stack_a)->x > (*stack_a)->next->x)
			rotate(stack_a, 'a');
	}
	else
		algo(stack_a, stack_b, size);
}
