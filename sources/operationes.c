/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:18:34 by hassende          #+#    #+#             */
/*   Updated: 2024/12/17 19:30:25 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	*stack = second;
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	r_rotate(t_stack **stack)
{
	t_stack	*second_last;
	t_stack	*last;

	second_last = NULL;
	last = *stack;
	while (last -> next)
	{
		second_last = last;
		last = last -> next;
	}
	last->next = *stack;
	last->prev = NULL;
	second_last->next = NULL;
	(*stack)->prev = last;
	*stack = last;
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;

	if (!*stack_b)
		return ;
	first = *stack_b;
	*stack_b = first->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	first->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = first;
	*stack_a = first;
	ft_putendl_fd("pa", 1);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;

	if (!*stack_a)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	first->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = first;
	*stack_b = first;
	ft_putendl_fd("pb", 1);
}
