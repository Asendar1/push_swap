/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:34:31 by hassende          #+#    #+#             */
/*   Updated: 2024/12/01 18:29:58 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	fill_list(t_stack **stack_a, char **args)
// {

// }

void	init_stack(t_stack **stack_a, char **args)
{
	int		i;

	i = 0;
	*stack_a = NULL;
	if (!stack_a)
		exit_error("Error\nMalloc failed");
	while (args[i])
	{
		if (!is_number(args[i]))
		{
			free_stack(stack_a);
			free_2d(args);
			exit_error("Error\nInvalid argument");
		}
		stack_add_bottom(stack_a, new_node(ft_atoi(args[i])));
		if (!*stack_a)
		{
			free_2d(args);
			exit(1);
		}
		i++;
	}
	for (t_stack *tmp = *stack_a; tmp; tmp = tmp->next)
		printf("%d\n", tmp->value);
	free_stack(stack_a);
}
