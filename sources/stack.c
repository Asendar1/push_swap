/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:34:31 by hassende          #+#    #+#             */
/*   Updated: 2024/11/28 21:42:35 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_atol(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			exit_error("Error\nInvalid argument");
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (result * sign > INT_MAX || result * sign < INT_MIN)
		exit_error("Error\nArgument out of range");
	return (result * sign);
}

void	init_stack(t_stack **stack_a, char **args)
{
	int		i;

	i = 0;
	while (args[i])
	{
		if (!ft_isdigit(args[i]))
		{
			free(*stack_a);
			exit_error("Error\nInvalid argument");
		}
		(*stack_a)->value = ft_atol(args[i]);
		(*stack_a)->index = i;
		(*stack_a)->push_cost = 0;
		(*stack_a)->above_median = false;
		(*stack_a)->cheapest = false;
		(*stack_a)->target_node = NULL;
		(*stack_a)->next = NULL;
		(*stack_a)->prev = NULL;
	}
}
