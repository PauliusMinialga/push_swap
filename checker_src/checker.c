/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 09:58:06 by pminialg      #+#    #+#                 */
/*   Updated: 2024/02/22 10:09:32 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

int	check_ok_or_ko(t_stack **a, t_stack **b, int len)
{
	int	value;

	value = 2;
	if (is_sorted(a) && stack_length(*a) == len)
	{
		write(1, "OK\n", 3);
		value = 1;
	}
	else
	{
		write(1, "KO\n", 3);
		value = 0;
	}
	stack_clear(a);
	stack_clear(b);
	return (value);
}

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 == *str2 && *str1)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

void	error(t_stack **a, t_stack **b, char **command)
{
	free(*command);
	stack_clear(a);
	stack_clear(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	do_command(t_stack **a, t_stack **b, char *command)
{
	if (!ft_strcmp(command, "pa\n"))
		pa(a, b, false);
	else if (!ft_strcmp(command, "pb\n"))
		pb(a, b, false);
	else if (!ft_strcmp(command, "sa\n"))
		sa(a, false);
	else if (!ft_strcmp(command, "sb\n"))
		sb(b, false);
	else if (!ft_strcmp(command, "ss\n"))
		ss(a, b, false);
	else if (!ft_strcmp(command, "ra\n"))
		ra(a, false);
	else if (!ft_strcmp(command, "rb\n"))
		rb(b, false);
	else if (!ft_strcmp(command, "rr\n"))
		rr(a, b, false);
	else if (!ft_strcmp(command, "rra\n"))
		rra(a, false);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(b, false);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(a, b, false);
	else
		error(a, b, &command);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*command;
	int		len;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	else
		argv = process_argv(argc, argv);
	init_stack(&a, argv, argc);
	len = stack_length(a);
	command = get_next_line(STDIN_FILENO);
	while (command)
	{
		do_command(&a, &b, command);
		free(command);
		command = get_next_line(STDIN_FILENO);
	}
	if (check_ok_or_ko(&a, &b, len) == 0)
		exit (1);
	return (EXIT_SUCCESS);
}
