/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarie <mmarie@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2023/09/29 20:36:24 by mmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(Node **stack)
{
	Node	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(Node **liste_a, Node **liste_b)
{
	Node	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *liste_a;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(liste_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *liste_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(liste_a);
			else
				pb(liste_a, liste_b);
		}
		while (ft_lstsize(*liste_b) != 0)
			pa(liste_a, liste_b);
		i++;
	}
}
