/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarie <mmarie@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2023/10/04 18:29:42 by mmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define NULL __null
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

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}				Node;

Node	*ft_lstnew(int content);
Node	*ft_lstlast(Node *head);
void	ft_lstadd_front(Node **stack, Node *new);
void	ft_lstadd_back(Node **stack, Node *new);
void	printList(Node *head);
int		ft_lstsize(Node *head);

void	ft_error(char *msg);
void	ft_check_args(int argc, char **argv);
int		is_sorted(Node **stack);
int		get_distance(Node **stack, int index);
void	make_top(Node **stack, int distance);
void	free_stack(Node **stack);
void	ft_free(char **str);
void	sort4_2(Node **liste_a, Node **liste_b);

// RADIXX
void	radix_sort(Node **liste_a, Node **liste_b);
void	simple_sort(Node **liste_a, Node **liste_b);
void	index_stack(Node **stack);
void	sort_5(Node **liste_a, Node **liste_b);
int		view_sort(Node **liste_a);
//static int	get_min(Node **liste_a, int val);
//static int	get_max(Node **liste_a, int val);
//
//static int	ft_count_words(char const *str, char c);
//static char	*ft_putword(char *word, char const *s, int i, int word_len);
//static char	**ft_split_words(char const *s, char c, char **s2, int num_words);
int		swap(Node **stack);
int		push(Node **stack_to, Node **stack_from);
int		rotate(Node **stack);
int		reverseRotate(Node **stack);

int		sa(Node **liste_a);
int		sb(Node **liste_b);
int		ss(Node **liste_a, Node **liste_b);
int		pa(Node **liste_a, Node **liste_b);
int		pb(Node **liste_b, Node **liste_a);
int		ra(Node **liste_a);
int		rb(Node **liste_b);
int		rr(Node **liste_a, Node **liste_b);
int		rra(Node **liste_a);
int		rrb(Node **liste_b);
int		rrr(Node **liste_a, Node **liste_b);

#endif
