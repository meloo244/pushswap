/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarie <mmarie@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:21:46 by mmarie            #+#    #+#             */
/*   Updated: 2023/10/12 13:19:31 by mmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# define INT_MAX 2147483647
//# define INT_MIN -2147483648

# include "../libft/libft.h"
# include <limits.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdbool.h>

/* STRUCTURE */
typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}				t_node;

/* FUNCTION LISTE CHAINE */
t_node	*ft_lstnew(int content);
t_node	*ft_lstlast(t_node *head);
void	ft_lstadd_front(t_node **stack, t_node *new);
void	ft_lstadd_back(t_node **stack, t_node *new);
void	printlist(t_node *head);
int		ft_lstsize(t_node *head);

/* OTHER FUNCTION */
void	ft_error(char *msg);
void	ft_check_args(int argc, char **argv);
int		is_sorted(t_node **stack);
void	free_stack(t_node **stack);
void	ft_free(char **str);
void	initstack(t_node **stack, int argc, char **argv);

/* RADIX */
void	radix_sort(t_node **stack_a, t_node **stack_b);
void	simple_sort(t_node **stack_a, t_node **stack_b);
void	index_stack(t_node **stack);

/* ARCHITECTURE MOUV */
int		swap(t_node **stack);
int		push(t_node **stack_to, t_node **stack_from);
int		rotate(t_node **stack);
int		reverserotate(t_node **stack);

/* MOUVEMENT */
int		sa(t_node **stack_a);
int		sb(t_node **stack_b);
int		ss(t_node **stack_a, t_node **stack_b);
int		pa(t_node **stack_a, t_node **stack_b);
int		pb(t_node **stack_b, t_node **stack_a);
int		ra(t_node **stack_a);
int		rb(t_node **stack_b);
int		rr(t_node **stack_a, t_node **stack_b);
int		rra(t_node **stack_a);
int		rrb(t_node **stack_b);
int		rrr(t_node **stack_a, t_node **stack_b);

/* SORT */
int		view_sort(t_node *stack_a);
void	sort3(t_node **stack_a);
void	sort4(t_node **stack_a, t_node **stack_b);
void	sort_5(t_node **stack_a, t_node **stack_b);

#endif
