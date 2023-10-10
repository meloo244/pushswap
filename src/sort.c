/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarie <mmarie@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:13:04 by mmarie            #+#    #+#             */
/*   Updated: 2023/10/10 21:21:23 by mmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void	sort3(Node **stack_a)
{
	while (view_sort(stack_a) == 0)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
		if ((*stack_a)->next->content > (*stack_a)->next->next->content)
			rra(stack_a);
	}
}

void	sort4(Node **stack_a, Node** stack_b)
{
	if (view_sort(stack_a) == 1)
		return;
	if ((*stack_a)->index == 1)
		pb(stack_a, stack_b);
	else if ((*stack_a)->next->index == 1)
	{
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->index == 1)
	{
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->next->index == 1)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	sort3(stack_a);
	pa(stack_b, stack_a);
}

void	sort5(Node **stack_a, Node **stack_b)
{
	int	nbv;

	nbv = 0;
	while(nbv != 2)
	{
		if((*stack_a)->index == 1 || (*stack_a)->index == 2)
		{
			pb(stack_a, stack_b);
			nbv++;
		}
		(*stack_a) = (*stack_a)->next;
	}
	sort3(stack_a);
	if((*stack_b)->content < (*stack_b)->next->content)
		swap(stack_b);
	push(stack_b, stack_a);
	push(stack_b, stack_a);
}

void	simple_sort(Node **stack_a, Node **stack_b)
{
	int	size;

	if (is_sorted(stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort3(stack_a);
	else if (size == 4)
		sort4(stack_a, stack_b);
}

int	view_sort(Node **stack_a)
{
	while((*stack_a)->next != NULL)
	{
		if((*stack_a)->content > (*stack_a)->next->content)
			return(0);
		(*stack_a) = (*stack_a)->next;
	}
	return(1);
}
