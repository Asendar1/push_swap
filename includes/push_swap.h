/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:51:22 by hassende          #+#    #+#             */
/*   Updated: 2024/11/28 21:20:50 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#include "libft.h"

struct s_stack
{
	int		value;
	int		index;
	int		push_cost;
	bool	above_median;
	bool	cheapest;
	t_stack *target_node;
	t_stack *next;
	t_stack *prev;

} typedef t_stack;

void	exit_error(char *error);

#endif
