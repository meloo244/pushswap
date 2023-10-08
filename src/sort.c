/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarie <mmarie@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 20:25:04 by mmarie            #+#    #+#             */
/*   Updated: 2023/10/04 20:00:35 by mmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void	ft_printlist(Node **liste_a)
{
	Node **tmp;

	tmp = liste_a;
	while (*tmp != NULL)
	{
		ft_putnbr_fd((*tmp)->content, 1);
		ft_putstr_fd("\n", 1);
		*tmp = (*tmp)->next;
	}
	ft_putstr_fd("\n", 1);
}

void	sort3(Node **liste_a)
{
	while (view_sort(liste_a) == 0)
	{
		if ((*liste_a)->content > (*liste_a)->next->content)
			sa(liste_a);
		if ((*liste_a)->next->content > (*liste_a)->next->next->content)
			rra(liste_a);
	}
}

void	sort4(Node **liste_a, Node** liste_b)
{
	if (view_sort(liste_a) == 1)
		return;
	if ((*liste_a)->index == 1)
		pb(liste_a, liste_b);
	else if ((*liste_a)->next->index == 1)
	{
		ra(liste_a);
		pb(liste_a, liste_b);
	}
	else if ((*liste_a)->next->next->index == 1)
	{
		ra(liste_a);
		ra(liste_a);
		pb(liste_a, liste_b);
	}
	else if ((*liste_a)->next->next->next->index == 1)
	{
		rra(liste_a);
		pb(liste_a, liste_b);
	}
	sort3(liste_a);
	pa(liste_b, liste_a);
}

void	sort5(Node **liste_a, Node **liste_b)
{
	int	nbv;

	nbv = 0;
	while(nbv != 2)
	{
		if((*liste_a)->index == 1 || (*liste_a)->index == 2)
		{
			pb(liste_a, liste_b);
			nbv++;
		}
		(*liste_a) = (*liste_a)->next;
	}
	sort3(liste_a);
	if((*liste_b)->content < (*liste_b)->next->content)
		swap(liste_b);
	push(liste_b, liste_a);
	push(liste_b, liste_a);
}

int	view_sort(Node **liste_a)
{
	int	i;

	i = 1;
	while((*liste_a) != NULL)
	{
		if((*liste_a)->index == i) // et = 1
			*liste_a = (*liste_a)->next;
		else
			return(0);
		i++;
	}
	return(1);
}

/*
static int	get_min(Node **liste_a, int val)
{
	Node	*head;
	int		min;

	head = *liste_a;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}*/

/*static int	get_max(Node **liste_a, int val)
{
	Node	*head;
	int		max;

	head = liste_a;
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
