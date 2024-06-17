/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/01 11:47:05 by pminialg      #+#    #+#                 */
/*   Updated: 2024/02/21 09:59:00 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*push_node;

	if (src == NULL || *src == NULL)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (dest == NULL || *dest == NULL)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->prev = push_node;
		*dest = push_node;
	}
}

void	pa(t_stack **a, t_stack **b, bool text)
{
	push(a, b);
	if (text)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, bool text)
{
	push(b, a);
	if (text)
		write(1, "pb\n", 3);
}
