/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:51:22 by hassende          #+#    #+#             */
/*   Updated: 2024/12/01 18:18:36 by hassende         ###   ########.fr       */
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
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;

}		t_stack;

void	exit_error(char *error);
void	init_stack(t_stack **stack_a, char **args);
void	stack_add_bottom(t_stack **stack, t_stack *node);
void	free_stack(t_stack **stack);
void	free_2d(char **arr);
int		ft_atol(char *str);
int		is_number(char *str);
t_stack	*new_node(int value);

#endif
