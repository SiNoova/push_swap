/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 06:14:32 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/04 06:40:33 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
    int x;
    struct s_node *next;
}t_node;

int	my_atoi(char *str);
t_node *ft_lstnew(int x);
void ft_lstadd_back(t_node **lst, t_node *new);
char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_split(char const *s, char c);
int ft_strlen(const char *str);
void ft_lstiter(t_node *node);

#endif