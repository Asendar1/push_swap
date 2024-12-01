/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:39:09 by hassende          #+#    #+#             */
/*   Updated: 2024/12/01 18:26:07 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	if (value == -1)
	{
		ft_putendl_fd("Error\nInteger overflow", 2);
		return (NULL);
	}
	node = malloc(sizeof(t_stack));
	if (!node)
		exit_error("Error\nMalloc failed");
	node->value = value;
	node->index = 0;
	node->push_cost = 0;
	node->above_median = false;
	node->cheapest = false;
	node->target_node = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	stack_add_bottom(t_stack **stack, t_stack *node)
{
	t_stack	*last;

	if (!node)
	{
		free_stack(stack);
		return ;
	}
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = node;
	node->prev = last;
}
