/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 09:57:39 by pminialg      #+#    #+#                 */
/*   Updated: 2024/02/22 10:02:28 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "../includes/push_swap.h"
# include <string.h>
# include <fcntl.h>
# include <ctype.h>

# define OPEN_MAX 1024

int		check_ok_or_ko(t_stack **a, t_stack **b, int len);
int		ft_strcmp(char *str1, char *str2);
void	error(t_stack **a, t_stack **b, char **command);
void	do_command(t_stack **a, t_stack **b, char *command);

char	*ft_free_gnl(char **string);
char	*next_line_data(char *buffer, char **line_data);
char	*get_line_from_buffer(char *buffer);
char	*read_data_from_file(char *result, int fd);
char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin_checker(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// commands
void	sa(t_stack **a, bool text);
void	sb(t_stack **b, bool text);
void	ss(t_stack **a, t_stack **b, bool text);
void	ra(t_stack **a, bool text);
void	rb(t_stack **b, bool text);
void	rr(t_stack **a, t_stack **b, bool text);
void	rra(t_stack **a, bool text);
void	rrb(t_stack **b, bool text);
void	rrr(t_stack **a, t_stack **b, bool text);
void	pa(t_stack **a, t_stack **b, bool text);
void	pb(t_stack **a, t_stack **b, bool text);

void	init_stack(t_stack **a, char **arguments, int argc);
int		stack_length(t_stack *stack);
bool	is_sorted(t_stack **stack);
void	stack_clear(t_stack **stack);
char	**process_argv(int argc, char **argv);

#endif