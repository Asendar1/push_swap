/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:34:31 by hassende          #+#    #+#             */
/*   Updated: 2024/12/15 14:28:51 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	short_sort(t_stack **stack_a)
{
	if (ft_stack_size(stack_a) == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
	if (ft_stack_size(stack_a) == 3)
	{
		if (((*stack_a)->value > (*stack_a)->next->value) && (*stack_a)->value > (*stack_a)->next->next->value)
			ra(stack_a);
		if ((*stack_a)->next->value > (*stack_a)->next->next->value)
			rra(stack_a);
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
}

int	ft_stack_max(t_stack **stack)
{
	int		max;
	t_stack	*tmp;

	max = INT_MIN;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	ft_stack_min(t_stack **stack)
{
	int		min;
	t_stack	*tmp;

	min = INT_MAX;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		j;
	int		max;
	int		min;

	i = 0;
	max = ft_stack_max(stack_a);
	min = ft_stack_min(stack_a);
	while (i < 32)
	{
		j = 0;
		while (j < ft_stack_size(stack_a))
		{
			if (((*stack_a)->value >> i) & 1)
				ra(stack_a);
			else
				push_b(stack_a, stack_b);
			j++;
		}
		while (ft_stack_size(stack_b))
			push_a(stack_a, stack_b);
		i++;
	}
}

void	algrothim(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_size(stack_a) <= 3)
		short_sort(stack_a);
	if (ft_stack_size(stack_a) > 5)
		radix_sort(stack_a, stack_b);
}

void	init_stack(t_stack **stack_a, char **args)
{
	int		i;

	i = 0;
	*stack_a = NULL;
	while (args[i])
	{
		if (!is_number(args[i]))
		{
			free_stack(stack_a);
			free_2d(args);
			exit_error("Error\nInvalid argument");
		}
		stack_add_bottom(args, stack_a, new_node(ft_atoi(args[i])));
		i++;
	}
}
