/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:42:55 by izperez           #+#    #+#             */
/*   Updated: 2024/05/01 11:56:56 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* If the stack is empty or if there has sth */
static void	pa_aux(t_psl *a, t_psl *b, t_stack *temp)
{
	if (a->first == NULL)
	{
		a->first = temp;
		b->last = temp;
		temp->next = temp;
		temp->prev = temp;
		a->size++;
		b->size--;
	}
	else
	{
		temp->next = a->first;
		temp->prev = a->last;
		a->first->prev = temp;
		a->last->next = temp;
		a->first = temp;
		a->size++;
		b->size--;
	}
}

/* push a: Takes the first element from the stack_b
adds at the top of the stack_a
If the stack is empty does nothing */
void	pa(t_psl *a, t_psl *b)
{
	t_stack	*temp;

	if (b == NULL || b->first == NULL)
		return ;
	temp = b->first;
	if (b->size == 0)
	{
		b->first = NULL;
		b->last = NULL;
		free(b);
		b = NULL;
		return ;
	}
	else
	{
		b->first = b->first->next;
		b->first->prev = b->last;
		b->last->next = b->first;
	}
	pa_aux(a, b, temp);
}

/* If the stack is empty or if there has sth */
static void	pb_aux(t_psl *a, t_psl *b, t_stack *temp)
{
	if (b->first == NULL)
	{
		b->first = temp;
		b->last = temp;
		temp->next = temp;
		temp->prev = temp;
		a->size--;
		b->size++;
	}
	else
	{
		temp->next = b->first;
		temp->prev = b->last;
		b->first->prev = temp;
		b->last->next = temp;
		b->first = temp;
		a->size--;
		b->size++;
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
	pb_aux(a, b, temp);
}
