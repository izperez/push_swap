/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:42:55 by izperez           #+#    #+#             */
/*   Updated: 2024/03/26 13:25:55 by izperez          ###   ########.fr       */
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
	if (temp->prev != NULL)
		temp->prev->next = b->first;
	if (b->first != NULL)
		b->first->prev = temp->prev;
	temp->next = a->first;
	if (a->first != NULL)
		a->first->prev = temp;
	a->first = temp;
	if (a->last != NULL)
		a->last->next = temp;
	else
		a->last = temp;
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
	if (temp->prev != NULL)
		temp->prev->next = a->first;
	if (a->first != NULL)
		a->first->prev = temp->prev;
	temp->next = b->first;
	if (b->first != NULL)
		b->first->prev = temp;
	b->first = temp;
	if (b->last != NULL)
		b->last->next = temp;
	else
		b->last = temp;
}
