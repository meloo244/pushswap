

#include "push_swap.h"

// Swaps first two elements of a stack | sa and sb

int	swap(Node **stack)
{
	Node	*head;
	Node	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		ft_error("Error occured while swapping!");
	tmp_val = head->content;
	tmp_index = head->index;
	head->content = next->content;
	head->index = next->index;
	next->content = tmp_val;
	next->index = tmp_index;
	return (0);
}

int	sa(Node **liste_a)
{
	if (swap(liste_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(Node **liste_b)
{
	if (swap(liste_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(Node **liste_a, Node **liste_b)
{
	if ((ft_lstsize(*liste_a) < 2) || (ft_lstsize(*liste_b) < 2))
		return (-1);
	swap(liste_a);
	swap(liste_b);
	ft_putendl_fd("ss", 1);
	return (0);
}

int	push(Node **stack_to, Node **stack_from)
{
	Node	*tmp;
	Node	*head_to;
	Node	*head_from;

	if (ft_lstsize(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
}

int	pa(Node **liste_a, Node **liste_b)
{
	if (push(liste_a, liste_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(Node **liste_a, Node **liste_b)
{
	if (push(liste_b, liste_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}

int	rotate(Node **stack)
{
	Node	*head;
	Node	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	ra(Node **liste_a)
{
	if (rotate(liste_a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(Node **liste_b)
{
	if (rotate(liste_b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(Node **liste_a, Node **liste_b)
{
	if ((ft_lstsize(*liste_a) < 2) || (ft_lstsize(*liste_b) < 2))
		return (-1);
	rotate(liste_a);
	rotate(liste_b);
	ft_putendl_fd("rr", 1);
	return (0);
}

int	reverseRotate(Node **stack)
{
	Node	*head;
	Node	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			 head->next = NULL;
			 break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	rra(Node **liste_a)
{
	if (reverseRotate(liste_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(Node **liste_b)
{
	if (reverseRotate(liste_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(Node **liste_a, Node **liste_b)
{
	if ((ft_lstsize(*liste_a) < 2) || (ft_lstsize(*liste_b) < 2))
		return (-1);
	reverseRotate(liste_a);
	reverseRotate(liste_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
