/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:55:36 by codespace         #+#    #+#             */
/*   Updated: 2024/07/08 17:35:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sorter(t_node **stack_a, t_node **stack_b, int size)
{
	int i;
	t_node *tmp;

	i = size - 1;
	position(*stack_b);
	while (i >= 0)
	{
		tmp = *stack_b;
		set_index(*stack_b);
		if (!i)
		{
			pa(stack_a, stack_b);
			break;
		}
		while (tmp && tmp->pos != i)
			tmp = tmp->next;
		if (tmp && tmp->index + 1 <= size / 2)
		{

			while (tmp->index != 0)
			{
				set_index(*stack_b);
				rotate(stack_b, 'b');
			}
		}
		else
		{
			while (tmp->index)
			{
				set_index(*stack_b);
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
	sorter(stack_a, stack_b, size);
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