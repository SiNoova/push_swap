/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 06:14:32 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/05 09:59:16 by akoutate         ###   ########.fr       */
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
int ft_lstsize(t_node *lst);
void pa(t_node **stack_a, t_node **stack_b);
void pb(t_node **stack_a, t_node **stack_b);
t_node	*ft_lstlast(t_node *lst);
void rotate(t_node **stack, char c);

#endif