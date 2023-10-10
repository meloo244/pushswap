/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarie <mmarie@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:01:07 by mmarie            #+#    #+#             */
/*   Updated: 2023/10/11 00:48:02 by mmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "../includes/push_swap.h"

static void	do_move2(Node **stack_a, Node **stack_b, char *line)
{
	if (ft_strncmp(line, "pa\n", 3) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push(stack_a, stack_b);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		swap(stack_a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		swap(stack_b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
	else
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

static void	do_move(Node **stack_a, Node **stack_b, char *line)
{
	if (ft_strncmp(line, "rra\n", 4) == 0)
		reverserotate(stack_a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		reverserotate(stack_b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
	{
		reverserotate(stack_a);
		reverserotate(stack_b);
	}
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate(stack_a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate(stack_a);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
	{
		rotate(stack_b);
		rotate(stack_a);
	}
	else
		do_move2(stack_a, stack_b, line);
}

void	checker(Node **stack_a, Node **stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		do_move(stack_a, stack_b, line);
		free(line);
	}
	if (view_sort(stack_a) == 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	Node	**stack_a;
	Node	**stack_b;

	if (argc < 2)
		return (0);
	stack_a = (Node **)malloc(sizeof(Node));
	stack_b = (Node **)malloc(sizeof(Node));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_check_args(argc, argv);
	initstack(stack_a, argc, argv);
	checker((stack_a), (stack_b));
	return (0);
}
