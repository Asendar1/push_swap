/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:51:22 by hassende          #+#    #+#             */
/*   Updated: 2024/12/17 18:35:51 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

# include "libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}		t_stack;

void	exit_error(char *error);
void	init_stack(t_stack **stack_a, char **args);
void	stack_add_bottom(char **args, t_stack **stack, t_stack *node);
void	free_stack(t_stack **stack);
void	free_2d(char **arr);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	r_rotate(t_stack **stack);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	algrothim(t_stack **stack_a, t_stack **stack_b);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
int		ft_stack_size(t_stack **stack);
int		is_number(char *str);
int		stack_sorted(t_stack **stack);
t_stack	*find_min(t_stack **stack);
t_stack	*new_node(long int value);

#endif
