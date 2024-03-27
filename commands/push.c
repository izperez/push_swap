/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:42:55 by izperez           #+#    #+#             */
/*   Updated: 2024/03/27 12:11:31 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* push a: Takes the first element from the stack_b
adds at the top of the stack_a
If the stack is empty does nothing */
void	pa(t_psl *a, t_psl *b)
{
	t_stack	*temp;

	if (b == NULL || b->first == NULL)
		return ;
	temp = b->first;
	b->first = b->first->next;
	b->first->prev = b->last;
	b->last->next = b->first;
	if (a->first == NULL)
	{
		a->first = temp;
		b->last = temp;
		temp->next = temp;
		temp->prev = temp;
	}
	else
	{
		temp->next = a->first;
		temp->prev = a->last;
		a->first->prev = temp;
		a->last->next = temp;
		a->first = temp;
	}
}

/* push b: Takes the first element from the stack_a
adds at the top of the stack_b
If the stack is empty does nothing */
void	pb(t_psl *a, t_psl *b)
{
	t_stack	*temp;

	if (a == NULL || a->first == NULL)
		return ;
	temp = a->first;
	a->first = a->first->next;
	a->first->prev = a->last;
	a->last->next = a->first;
	if (b->first == NULL)
	{
		b->first = temp;
		b->last = temp;
		temp->next = temp;
		temp->prev = temp;
	}
	else
	{
		temp->next = b->first;
		temp->prev = b->last;
		b->first->prev = temp;
		b->last->next = temp;
		b->first = temp;
	}
}
