/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 02:25:28 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/05 10:13:43 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *stack, char c)
{
	if (ft_lstsize(stack) > 1)
	{
		int	tmp;
		tmp = stack->x;
		stack->x = stack->next->x;
		stack->next->x = tmp;
	}
	if (c == 'a')
		write(1, "sa\n", 4);
	else if (c == 'b')
		write(1, "sb\n", 4);
}


void ss(t_node *stack_a, t_node *stack_b)
{
	swap(stack_a, '1');
	swap(stack_b, '1');
	write(1, "ss\n", 4);
}

void pa(t_node **stack_a, t_node **stack_b)
{
	if (*stack_b)
	{
		t_node *tmp;

		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
	write(1, "pa\n", 3);
}

void pb(t_node **stack_a, t_node **stack_b)
{
	if (*stack_a)
	{
		t_node *tmp;

		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
	write(1, "pb\n", 3);
}

void rotate(t_node **stack, char c)
{
	if (ft_lstsize(*stack) > 1)
	{
		t_node *tmp;
		
		tmp = *stack;
		*stack = (*stack)->next;
		ft_lstlast(tmp)->next = tmp;
		tmp->next = NULL;
	}
	if (c == 'a')
		write (1, "ra\n", 3);
	else if (c == 'b')
		write (1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a, '3');
	rotate(stack_b, '3');
	write(1, "rr\n", 3);
}

void	rrotate(t_node **stack, char c)
{
	if (ft_lstsize(*stack) > 1)
	{
		t_node *tmp;
		
		tmp = *stack;
		*stack = ft_lstlast(tmp);
		ft_lstlast(tmp)->next = tmp;
		tmp->next = NULL;
	}
	if (c == 'a')
		write (1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void rrr(t_node **stack_a, t_node **stack_b)
{
	rrotate(stack_a, '2');
	rrotate(stack_b, '2');
	write(1, "rrr\n", 4);
}