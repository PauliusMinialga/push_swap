/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/24 14:56:10 by pminialg      #+#    #+#                 */
/*   Updated: 2024/02/21 14:21:47 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

// node in the stack
typedef struct s_stack
{
	int				data;
	int				current_position;
	int				final_index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// a_to_b.c
void	set_current_position(t_stack *stack);
void	set_target_node_a(t_stack *a, t_stack *b);
void	set_cost(t_stack *a, t_stack *b);
void	cheapest_node_to_push(t_stack *b);
void	fill_stacks_a(t_stack *a, t_stack *b);

// b_to_a.c
void	put_on_top(t_stack *top_node, t_stack **a);
void	set_target_node_b(t_stack *a, t_stack *b);
void	fill_stacks_b(t_stack *a, t_stack *b);
int		get_divergence(t_stack *a, int len_a, int len_b);
int		max_moves(int a, int b);

// handle_errors.c
bool	is_sorted(t_stack **stack);
int		check_argv(char *argument);
int		check_dup(int nbr, t_stack *stack);
void	stack_clear(t_stack **stack);
void	err_clean(t_stack **stack, char **argumnet, int argc);

// init_stack.c
void	init_stack(t_stack **a, char **arguments, int argc);
void	append_node(int nbr, t_stack **a);
t_stack	*cheapest_node(t_stack *stack);
void	cheapest_on_top(t_stack **stack, t_stack *top_node,
			char stack_name);
void	ft_free(char **str);

// push.c
void	push(t_stack **dest, t_stack **src);
void	pa(t_stack **a, t_stack **b, bool text);
void	pb(t_stack **a, t_stack **b, bool text);

// rev_rotate.c bottom to top
void	rev_rotate(t_stack **stack);
void	rra(t_stack **a, bool text);
void	rrb(t_stack **b, bool text);
void	rrr(t_stack **a, t_stack **b, bool text);

// rotate.c top to bottom
void	rotate(t_stack **stack);
void	ra(t_stack **a, bool text);
void	rb(t_stack **b, bool text);
void	rr(t_stack **a, t_stack **b, bool text);

// small_sort.c
void	sort_three(t_stack **stack);
void	sort_five(t_stack **a, t_stack **b, int len_a);

// sort.c
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	node_move_a_to_b(t_stack **a, t_stack **b);
void	node_move_b_to_a(t_stack **a, t_stack **b);
void	sort_stack(t_stack **a, t_stack **b);
// swap.c
void	swap(t_stack **stack);
void	sa(t_stack **a, bool text);
void	sb(t_stack **b, bool text);
void	ss(t_stack **a, t_stack **b, bool text);

// utils.c
int		stack_length(t_stack *stack);
t_stack	*find_last_node(t_stack *stack);
t_stack	*highest_node(t_stack *stack);
t_stack	*smallest_node(t_stack *stack);
char	**process_argv(int argc, char **argv);

#endif