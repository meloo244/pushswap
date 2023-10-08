/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarie <mmarie@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2023/09/29 20:10:03 by mmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Node	*ft_lstnew(int content)
{
	Node	*new;

	new = (Node *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(Node **stack, Node *new)
{
	new->next = *stack;
	*stack = new;
}

Node	*ft_lstlast(Node *head)
{
	Node	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

void	ft_lstadd_back(Node **stack, Node *new)
{
	Node	*n;

	if (*stack)
	{
		n = ft_lstlast(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

int	ft_lstsize(Node *head)
{
	size_t	i;
	Node	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	printList(Node *head)
{
	Node	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->content, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
}
