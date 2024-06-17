/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 11:53:14 by pminialg      #+#    #+#                 */
/*   Updated: 2024/02/16 11:34:43 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_length(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack == NULL)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack	*find_last_node(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*highest_node(t_stack *stack)
{
	t_stack	*highest_node;
	t_stack	*current_node;

	if (stack == NULL)
		return (NULL);
	highest_node = stack;
	current_node = stack->next;
	while (current_node != NULL)
	{
		if (current_node->data > highest_node->data)
			highest_node = current_node;
		current_node = current_node->next;
	}
	return (highest_node);
}

t_stack	*smallest_node(t_stack *stack)
{
	t_stack	*current_node;
	t_stack	*smallest_node;

	if (stack == NULL)
		return (NULL);
	smallest_node = stack;
	current_node = stack->next;
	while (current_node != NULL)
	{
		if (current_node->data < smallest_node->data)
			smallest_node = current_node;
		current_node = current_node->next;
	}
	return (smallest_node);
}

char	**process_argv(int argc, char **argv)
{
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = &argv[1];
	return (argv);
}
