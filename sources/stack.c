/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:34:31 by hassende          #+#    #+#             */
/*   Updated: 2024/12/08 22:19:47 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algrothim(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_size(stack_a) == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
	if (ft_stack_size(stack_a) == 3)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
		ra(stack_a);
	}
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
		stack_add_bottom(stack_a, new_node(ft_atoi(args[i])));
		i++;
	}
}
