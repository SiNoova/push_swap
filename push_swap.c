/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 06:17:05 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/05 10:03:01 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int empty_str(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

int parsing(char **lst, char *str, int j)
{
	int i = 0;

	if (str[0] == '-' || str[0] == '+')
	{
		if (ft_strlen(str) == 1)
			return (0);
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	i = 0;
	while (i < j)
	{
		if (my_atoi(lst[i]) == my_atoi(str))
			return (0);
		i++;
	}
	return (1);
}

void leaks(void)
{
	system("leaks a.out");
}
int	main(int ac, char **av)
{
	int i = 1;
	char *str = "";
	char *tmp;
	t_node *head = NULL;
	t_node *stack_b = NULL;
	if(ac == 1)
		return (0);
	while (i < ac)
	{
		tmp = str;
		if (empty_str(av[i]))
			str = ft_strjoin(str, av[i]);
		else
		{
			write (1, "Error\n", 7);
			exit(1);
		}	
		if (i != 1)
			free(tmp);
		i++;
	}
	// printf("%s", str);
	char **split = ft_split(str, ' ');
	free(str);

	
	i = 0;
	while (split[i])
	{
		if (parsing(split, split[i], i))
		{
			// printf("%s ", split[i]);
			ft_lstadd_back(&head, ft_lstnew(my_atoi(split[i])));
			i++;
		}
		else
		{
			write(1, "Error\n", 7);
			exit(1);
		}
	}
	ft_lstiter(head);
	i = 0;
	while (split[i++])
		free(split[i]);
	free(split);
} 
