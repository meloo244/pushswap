/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarie <mmarie@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:21:46 by mmarie            #+#    #+#             */
/*   Updated: 2023/10/10 21:20:25 by mmarie           ###   ########.fr       */
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
}				Node;

/* FUNCTION LISTE CHAINE */
Node	*ft_lstnew(int content);
Node	*ft_lstlast(Node *head);
void	ft_lstadd_front(Node **stack, Node *new);
void	ft_lstadd_back(Node **stack, Node *new);
void	printlist(Node *head);
int		ft_lstsize(Node *head);

/* OTHER FUNCTION */
void	ft_error(char *msg);
void	ft_check_args(int argc, char **argv);
int		is_sorted(Node **stack);
void	free_stack(Node **stack);
void	ft_free(char **str);
void	initstack(Node **stack, int argc, char **argv);

/* RADIX */
void	radix_sort(Node **stack_a, Node **stack_b);
void	simple_sort(Node **stack_a, Node **stack_b);
void	index_stack(Node **stack);

/* ARCHITECTURE MOUV */
int		swap(Node **stack);
int		push(Node **stack_to, Node **stack_from);
int		rotate(Node **stack);
int		reverseRotate(Node **stack);

/* MOUVEMENT */
int		sa(Node **stack_a);
int		sb(Node **stack_b);
int		ss(Node **stack_a, Node **stack_b);
int		pa(Node **stack_a, Node **stack_b);
int		pb(Node **stack_b, Node **stack_a);
int		ra(Node **stack_a);
int		rb(Node **stack_b);
int		rr(Node **stack_a, Node **stack_b);
int		rra(Node **stack_a);
int		rrb(Node **stack_b);
int		rrr(Node **stack_a, Node **stack_b);

/* SORT */
int		view_sort(Node **stack_a);
void	sort3(Node **stack_a);
void	sort4(Node **stack_a, Node **stack_b);
void	sort_5(Node **stack_a, Node **stack_b);

#endif
