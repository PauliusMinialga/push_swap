/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/01 11:31:07 by pminialg      #+#    #+#                 */
/*   Updated: 2024/02/15 14:06:34 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*head;
	t_stack	*second_node;
	int		len;

	len = stack_length(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	head = *stack;
	second_node = head->next;
	head->next = second_node->next;
	second_node->next = head;
	if (head->next != NULL)
		head->next->prev = head;
	second_node->prev = head->prev;
	head->prev = second_node;
	*stack = second_node;
}

void	sa(t_stack **a, bool text)
{
	swap(a);
	if (text)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, bool text)
{
	swap(b);
	if (text)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, bool text)
{
	swap(a);
	swap(b);
	if (text)
		write(1, "ss\n", 3);
}
