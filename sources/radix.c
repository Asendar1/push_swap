/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:05:40 by hassende          #+#    #+#             */
/*   Updated: 2024/12/17 19:31:15 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*min_node;
	long	min;

	min = LONG_MAX;
	min_node = NULL;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->value < min && tmp->index == -1)
		{
			min = tmp->value;
			min_node = tmp;
		}
		tmp = tmp->next;
	}
	return (min_node);
}

static void	set_index(t_stack **stack_a)
{
	t_stack	*min_node;
	int		index;

	index = 0;
	while (1)
	{
		min_node = find_min(stack_a);
		if (!min_node)
			break ;
		min_node->index = index;
		index++;
	}
}

static void	set_size_and_max_bits(t_stack **stack_a, int *size, int *max_bits)
{
	int	bits;
	int	i;

	*size = ft_stack_size(stack_a);
	bits = 0;
	i = *size - 1;
	while ((i >> bits) != 0)
		bits++;
	*max_bits = bits;
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	set_index(stack_a);
	set_size_and_max_bits(stack_a, &size, &max_bits);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*stack_a)->index >> i) & 1)
				ra(stack_a);
			else
				push_b(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			push_a(stack_a, stack_b);
		i++;
	}
}
