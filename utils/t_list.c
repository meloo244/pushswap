/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarie <mmarie@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:40:28 by mmarie            #+#    #+#             */
/*   Updated: 2023/10/11 11:21:50 by mmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_lstnew(int content)
{
	t_node	*new;

	new = (t_node *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_node **stack, t_node *new)
{
	new->next = *stack;
	*stack = new;
}

t_node	*ft_lstlast(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

void	ft_lstadd_back(t_node **stack, t_node *new)
{
	t_node	*n;

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

int	ft_lstsize(t_node *head)
{
	size_t	i;
	t_node	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
