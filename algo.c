/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:55:36 by codespace         #+#    #+#             */
/*   Updated: 2024/07/08 12:31:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void algo(t_node *stack_a, t_node *stack_b)
{
	int size;

	size = ft_lstsize(stack_a);
	if (sorted_checker(stack_a))
		return ;
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if (stack_a->x > stack_a->next->x)
			rotate(&stack_a, 'a');
	}
	
}