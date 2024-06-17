/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   b_to_a.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/26 13:24:31 by pminialg      #+#    #+#                 */
/*   Updated: 2024/02/21 09:44:15 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	put_on_top(t_stack *top_node, t_stack **a)
{
	if (top_node->above_median)
		while (*a != top_node)
			ra(a, true);
	else
		while (*a != top_node)
			rra(a, true);
}

int	get_divergence(t_stack *a, int a_len, int b_len)
{
	a->push_cost = a->current_position;
	if (!(a->above_median))
		a->push_cost = a_len - (a->current_position);
	if (a->target_node->above_median)
		a->push_cost += a->target_node->current_position;
	else
		a->push_cost += b_len - (a->target_node->current_position);
	return (a->push_cost);
}

int	max_moves(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

void	set_target_node_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->data > b->data && current_a->data < best_match)
			{
				best_match = current_a->data;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = smallest_node(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	fill_stacks_b(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node_b(a, b);
}
