/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:39:09 by hassende          #+#    #+#             */
/*   Updated: 2024/12/08 22:39:49 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(long int value)
{
	t_stack	*node;

	if (value == LONG_MAX)
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
		exit (1);
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

int	ft_stack_size(t_stack **stack)
{
	t_stack	*tmp;
	int		size;

	size = 0;
	tmp = *stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
