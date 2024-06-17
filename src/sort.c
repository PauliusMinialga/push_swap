/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 13:49:31 by pminialg      #+#    #+#                 */
/*   Updated: 2024/02/21 10:53:54 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, true);
	set_current_position(*a);
	set_current_position(*b);
}

void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, true);
	set_current_position(*a);
	set_current_position(*b);
}

void	node_move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*best_node_to_push;

	best_node_to_push = cheapest_node(*a);
	if (best_node_to_push->above_median
		&& best_node_to_push->target_node->above_median)
	{
		rotate_both(a, b, best_node_to_push);
	}
	else if (!(best_node_to_push->above_median)
		&& !(best_node_to_push->target_node->above_median))
	{
		reverse_rotate_both(a, b, best_node_to_push);
	}
	cheapest_on_top(a, best_node_to_push, 'a');
	cheapest_on_top(b, best_node_to_push->target_node, 'b');
	pb(a, b, true);
}

void	node_move_b_to_a(t_stack **a, t_stack **b)
{
	cheapest_on_top(a, (*b)->target_node, 'a');
	pa(a, b, true);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int		len_a;
	t_stack	*top_node;

	len_a = stack_length(*a);
	if (len_a-- > 3 && !(is_sorted(a)))
		pb(a, b, true);
	if (len_a-- > 3 && !(is_sorted(a)))
		pb(a, b, true);
	while (len_a-- > 3 && !(is_sorted(a)))
	{
		fill_stacks_a(*a, *b);
		node_move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		fill_stacks_b(*a, *b);
		node_move_b_to_a(a, b);
	}
	set_current_position(*a);
	top_node = smallest_node(*a);
	put_on_top(top_node, a);
}
