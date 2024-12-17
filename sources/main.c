/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:50:51 by hassende          #+#    #+#             */
/*   Updated: 2024/12/17 19:21:05 by hassende         ###   ########.fr       */
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

void	check_duplicates(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
			{
				free_stack(stack);
				exit_error("Error\nDuplicates found");
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (!argv[1][0] && argc == 2))
		return (0);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = insert_args(argc, argv);
	init_stack(&stack_a, args);
	free_2d(args);
	check_duplicates(&stack_a);
	if (!stack_sorted(&stack_a))
		algrothim(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
