/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarie <mmarie@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2023/10/03 11:17:51 by mmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initStack(Node **stack, int argc, char **argv)
{
	Node	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_free(args);
}

static void	sort_stack(Node **liste_a, Node **liste_b)
{
	if (ft_lstsize(*liste_a) <= 4)
		simple_sort(liste_a, liste_b);
	else
		radix_sort(liste_a, liste_b);
}

int	main(int argc, char **argv)
{
	Node	**liste_a;
	Node	**liste_b;

	if (argc < 2)
		return (-1);
	ft_check_args(argc, argv);
	liste_a = (Node **)malloc(sizeof(Node));
	liste_b = (Node **)malloc(sizeof(Node));
	*liste_a = NULL;
	*liste_b = NULL;
	initStack(liste_a, argc, argv);
	if (is_sorted(liste_a))
	{
		free_stack(liste_a);
		free_stack(liste_b);
		return (0);
	}
	sort_stack(liste_a, liste_b);
	free_stack(liste_a);
	free_stack(liste_b);
	return (0);
}
