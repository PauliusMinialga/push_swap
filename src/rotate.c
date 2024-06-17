/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/01 11:48:04 by pminialg      #+#    #+#                 */
/*   Updated: 2024/02/15 14:50:53 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tail;
	int		len;

	len = stack_length(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	tail = find_last_node(*stack);
	tail->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tail->next->prev = tail;
	tail->next->next = NULL;
}

void	ra(t_stack **a, bool text)
{
	rotate(a);
	if (text)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, bool text)
{
	rotate(b);
	if (text)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, bool text)
{
	rotate(a);
	rotate(b);
	if (text)
		write(1, "rr\n", 3);
}
