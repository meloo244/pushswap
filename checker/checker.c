/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarie <mmarie@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:01:07 by mmarie            #+#    #+#             */
/*   Updated: 2023/10/12 15:00:40 by mmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "../includes/push_swap.h"

static void	do_move2(t_node **stack_a, t_node **stack_b, char *line)
{
	if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(stack_b, stack_a);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(stack_a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(stack_b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
	{
		ss(stack_a, stack_b);
	}
	else
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

static void	do_move(t_node **stack_a, t_node **stack_b, char *line)
{
	if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(stack_a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(stack_b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
	{
		rrr(stack_a, stack_b);
	}
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(stack_a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(stack_b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
	{
		rr(stack_a, stack_a);
	}
	else
		do_move2(stack_a, stack_b, line);
}

void	checker(t_node **stack_a, t_node **stack_b)
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
	if (view_sort(*stack_a) == 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;

	if (argc < 2)
		return (0);
	stack_a = (t_node **)malloc(sizeof(t_node));
	stack_b = (t_node **)malloc(sizeof(t_node));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_check_args(argc, argv);
	initstack(stack_a, argc, argv);
	checker((stack_a), (stack_b));
	return (0);
}
