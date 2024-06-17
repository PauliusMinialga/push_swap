/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 09:52:27 by pminialg      #+#    #+#                 */
/*   Updated: 2024/02/22 09:23:52 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	append_node(int nbr, t_stack **a)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (a == NULL)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return ;
	new_node->data = nbr;
	new_node->next = NULL;
	if (*a == NULL)
	{
		*a = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*a);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
	new_node->cheapest = false;
}

void	init_stack(t_stack **a, char **arguments, int argc)
{
	long	nbr;
	int		i;

	i = 0;
	while (arguments[i] != NULL)
	{
		if (check_argv(arguments[i]))
			err_clean(a, arguments, argc);
		nbr = ft_atol(arguments[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			err_clean(a, arguments, argc);
		if (check_dup((int)nbr, *a))
			err_clean(a, arguments, argc);
		append_node((int)nbr, a);
		i++;
	}
	if (argc == 2)
		ft_free(arguments);
}

t_stack	*cheapest_node(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack != NULL)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	cheapest_on_top(t_stack **stack, t_stack *top_node,
					char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	if (!*str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}
