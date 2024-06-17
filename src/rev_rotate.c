/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_rotate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/01 11:48:27 by pminialg      #+#    #+#                 */
/*   Updated: 2024/02/15 14:07:18 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*tail;
	int		len;

	len = stack_length(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	tail = find_last_node(*stack);
	tail->prev->next = NULL;
	tail->next = *stack;
	tail->prev = NULL;
	*stack = tail;
	tail->next->prev = tail;
}

void	rra(t_stack **a, bool text)
{
	rev_rotate(a);
	if (text)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, bool text)
{
	rev_rotate(b);
	if (text)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool text)
{
	rev_rotate(a);
	rev_rotate(b);
	if (text)
		write(1, "rrr\n", 4);
}
