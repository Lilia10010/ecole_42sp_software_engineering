#include "push_swap.h"

static void	rotate_first_to_last(t_node **stack)
{
	t_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_node **a)
{
	rotate_first_to_last(a);
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	rotate_first_to_last(b);
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rotate_first_to_last(a);
	rotate_first_to_last(b);
	write(1, "rr\n", 3);
}