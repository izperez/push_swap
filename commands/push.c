/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:42:55 by izperez           #+#    #+#             */
/*   Updated: 2024/03/26 10:46:13 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* push a: Takes the first element from the stack_b
adds at the top of the stack_a
If the stack is empty does nothing */
void	pa(t_stk **a, t_stk **b)
{
	t_stk	*temp;

	if (*b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	if (*b != NULL)
		(*b)->prev = NULL;
	temp->next = *a;
	if (*a != NULL)
		(*a)->prev = temp;
	*a = temp;
}

/* push b: Takes the first element from the stack_a
adds at the top of the stack_b
If the stack is empty does nothing */
void	pb(t_stk **a, t_stk **b)
{
	t_stk	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	if (*a != NULL)
		(*a)->prev = NULL;
	temp->next = *b;
	if (*b != NULL)
		(*b)->prev = temp;
	*b = temp;
}
