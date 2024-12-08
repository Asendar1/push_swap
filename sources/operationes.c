/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:18:34 by hassende          #+#    #+#             */
/*   Updated: 2024/12/08 15:08:47 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*head;
	t_stack	*next;
	
	head = *stack;
	next = (*stack) -> next;
	head->next = next -> next;
	head->prev = next;
	next->prev = NULL;
	next->next = head;
}

void	rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	first = *stack;
	last = *stack;
	while (last->next)
		last = last -> next;	
	*stack = first -> next;
	first -> next = NULL;
	first -> prev = last;
	last -> next = first;
	(*stack) -> prev = NULL;
}

void	r_rotate(t_stack **stack)
{
	t_stack *second_last;
	t_stack *last;
	
	second_last = NULL;
	last = *stack;
	while (last -> next)
	{
		second_last = last;
		last = last -> next;
	}
	*stack = last;
	second_last->next = NULL;
	last -> prev = NULL;
	last -> next = second_last;
	second_last->prev = last; // ? 5 4 1 2 3
}