/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:50:51 by hassende          #+#    #+#             */
/*   Updated: 2024/11/28 21:36:58 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || !argv[1][0] && argc == 2)
		exit_error("Error\nNo arguments provided");
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	init_stack(&stack_a, args);
	return (0);
}
