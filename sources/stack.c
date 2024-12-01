/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:34:31 by hassende          #+#    #+#             */
/*   Updated: 2024/12/01 17:55:21 by hassende         ###   ########.fr       */
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
			ft_putendl_fd("Error\nInvalid argument", 2);
			free_stack(stack_a);
			return ;
		}
		stack_add_bottom(stack_a, new_node(ft_atoi(args[i])));
		i++;
	}
	for (t_stack *tmp = *stack_a; tmp; tmp = tmp->next)
	{
		printf("%d\n", tmp->value);
	}
	free_stack(stack_a);
}
