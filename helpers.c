/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 07:54:39 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/04 06:32:33 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	my_atoi(char *str)
{
	int		i;
	int		sign;
    long     nbr;
        
	i = 0;
	sign = 1;
	nbr = 0;
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - 48);
		if (sign == -1)
		{
			if (-nbr < INT_MIN)
			{
				write(1, "Error\n", 7);
				exit(1);
			}
		}
		else if (nbr > INT_MAX)
		{
			write(1, "Error\n", 7);
			exit(1);
		}
		i++;
	}
	return (nbr * sign);
}

t_node *ft_lstnew(int x)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node	));
	if (!new_node)
		return (NULL);
	new_node->x = x;
	new_node->next = NULL;
	return (new_node);
}

void ft_lstadd_back(t_node **lst, t_node *new)
{
	if (!lst)
		return ;
	if (!new)
		return ;
	t_node *temp;
	
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while(temp->next)
		temp = temp->next;
	temp->next = new;
}
