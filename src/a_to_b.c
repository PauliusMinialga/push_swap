/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   a_to_b.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/01 10:47:52 by pminialg      #+#    #+#                 */
/*   Updated: 2024/02/21 09:41:53 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_current_position(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (stack == NULL)
		return ;
	median = stack_length(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	set_target_node_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target;
	long	best_match;

	while (a)
	{
		best_match = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->data < a->data && current_b->data > best_match)
			{
				best_match = current_b->data;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			a->target_node = highest_node(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

void	set_cost(t_stack *a, t_stack *b)
{
	int	a_len;
	int	b_len;
	int	divergence;
	int	up;
	int	down;

	a_len = stack_length(a);
	b_len = stack_length(b);
	while (a)
	{
		divergence = get_divergence(a, a_len, b_len);
		up = max_moves(a->current_position, a->target_node->current_position);
		down = max_moves(a_len - a->current_position,
				b_len - a->target_node->current_position);
		if (divergence <= up && divergence <= down)
			a->push_cost = divergence;
		else if (up < divergence && up < down)
			a->push_cost = up;
		else
			a->push_cost = down;
		a = a->next;
	}
}

void	cheapest_node_to_push(t_stack *stack)
{
	int		best_match;
	t_stack	*cheapest_node;

	if (stack == NULL)
		return ;
	cheapest_node = stack;
	best_match = INT_MAX;
	while (stack->next != NULL)
	{
		if (stack->push_cost < best_match)
		{
			best_match = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	fill_stacks_a(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node_a(a, b);
	set_cost(a, b);
	cheapest_node_to_push(a);
}
