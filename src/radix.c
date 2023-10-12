/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarie <mmarie@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:12:14 by mmarie            #+#    #+#             */
/*   Updated: 2023/10/12 13:21:06 by mmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*head_a;
	int		i;
	int		j;
	int		size;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a);
	while (view_sort(*stack_a) == 0)
	{
		j = 0;
		while (j++ < size && view_sort(*stack_a) == 0)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
