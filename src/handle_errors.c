/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_errors.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 11:33:23 by pminialg      #+#    #+#                 */
/*   Updated: 2024/02/21 14:21:59 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_sorted(t_stack **param)
{
	t_stack	*stack;

	stack = *param;
	if (stack == NULL || stack == NULL)
		return (true);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	check_argv(char *argument)
{
	int	i;

	i = 0;
	if (!((argument[i] == '+' || argument[i] == '-')
			|| (argument[i] >= '0' && argument[i] <= '9')))
		return (1);
	if ((argument[i] == '+' || argument[i] == '-')
		&& !(argument[1] >= '0' && argument[1] <= '9'))
		return (1);
	i++;
	while (argument[i])
	{
		if (!(argument[i] >= '0' && argument[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	check_dup(int nbr, t_stack *stack)
{
	if (stack == NULL)
		return (0);
	while (stack)
	{
		if (stack->data == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	stack_clear(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	err_clean(t_stack **stack, char **argument, int argc)
{
	stack_clear(stack);
	if (argc == 2)
		ft_free(argument);
	write(2, "Error\n", 6);
	exit(1);
}
