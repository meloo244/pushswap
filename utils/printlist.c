/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarie <mmarie@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:40:40 by mmarie            #+#    #+#             */
/*   Updated: 2023/10/11 11:21:50 by mmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	printlist(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->content, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
}
