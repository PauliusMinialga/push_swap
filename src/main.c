/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 09:34:04 by pminialg      #+#    #+#                 */
/*   Updated: 2024/02/21 13:35:44 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		len_a;

	a = NULL;
	b = NULL;
	if (argc == 1 || (2 == argc && !argv[1][0]))
		return (EXIT_SUCCESS);
	argv = process_argv(argc, argv);
	init_stack(&a, argv, argc);
	len_a = stack_length(a);
	if (!is_sorted(&a))
	{
		if (len_a == 2)
			sa(&a, true);
		else if (len_a == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	stack_clear(&a);
	return (EXIT_SUCCESS);
}
