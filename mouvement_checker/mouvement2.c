/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarie <mmarie@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:36:57 by mmarie            #+#    #+#             */
/*   Updated: 2023/10/13 01:32:43 by mmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	pa(t_node **stack_a, t_node **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	return (0);
}

int	pb(t_node **stack_a, t_node **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	return (0);
}

int	rotate(t_node **stack)
{
	t_node	*head;
	t_node	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	ra(t_node **stack_a)
{
	if (rotate(stack_a) == -1)
		return (-1);
	return (0);
}

int	rb(t_node **stack_b)
{
	if (rotate(stack_b) == -1)
		return (-1);
	return (0);
}
