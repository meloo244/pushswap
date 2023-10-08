/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarie <mmarie@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:13:04 by mmarie            #+#    #+#             */
/*   Updated: 2023/10/08 21:11:28 by mmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void	ft_printlist(Node **stack_a)
{
	Node **tmp;

	tmp = stack_a;
	while (*tmp != NULL)
	{
		ft_putnbr_fd((*tmp)->content, 1);
		ft_putstr_fd("\n", 1);
		*tmp = (*tmp)->next;
	}
	ft_putstr_fd("\n", 1);
}

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
/*
int	view_sort(Node **stack_a)
{
	int	i;

	i = 1;
	while((*stack_a) != NULL)
	{
		if((*stack_a)->index == i) // et = 1
			*stack_a = (*stack_a)->next;
		else
			return(0);
		i++;
	}
	return(1);
}*/

/*
static int	get_min(Node **stack_a, int val)
{
	Node	*head;
	int		min;

	head = *stack_a;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}*/

/*static int	get_max(Node **stack_a, int val)
{
	Node	*head;
	int		max;

	head = stack_a;
	max = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index > max) && head->index != val)
		max = head->index;
	}
	return (max);
}*/

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
