/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:50:51 by hassende          #+#    #+#             */
/*   Updated: 2024/12/09 13:19:34 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**insert_args(int argc, char **argv)
{
	char	**args;
	int		i;
	int		j;

	i = 1;
	j = 0;
	args = malloc(sizeof(char *) * (argc));
	while (i < argc)
	{
		args[j] = ft_strdup(argv[i]);
		i++;
		j++;
	}
	args[j] = NULL;
	return (args);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (!argv[1][0] && argc == 2))
		exit_error("Error\nUsage : ./push_swap [numbers]");
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = insert_args(argc, argv);
	init_stack(&stack_a, args);
	free_2d(args);
	algrothim(&stack_a, &stack_b);
	for (t_stack *tmp = stack_a; tmp; tmp = tmp->next)
		printf("%d\n", tmp->value);
	free_stack(&stack_a);
	return (0);
}
