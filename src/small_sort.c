/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 11:58:05 by pminialg      #+#    #+#                 */
/*   Updated: 2024/02/21 09:59:15 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*highest;

	highest = highest_node(*stack);
	if (*stack == highest)
		ra(stack, true);
	if ((*stack)->next == highest)
		rra(stack, true);
	if ((*stack)->data > (*stack)->next->data)
		sa(stack, true);
}
