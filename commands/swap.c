/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:29:17 by izperez           #+#    #+#             */
/*   Updated: 2024/03/26 11:09:42 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//swap a: swap the first two elements from the stack_a.
//Does nothing if there is <= 1 element.
void	sa(t_stk **a)
{
	t_stk	*temp;

	if (*a != NULL && (*a)->next != NULL)
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = (*a)->next;
		(*a)->next = temp;
	}
}

//swap b: Swap the first two elements from the stack_b.
//Does nothing if there is <= 1 element.
void	sb(t_stk **b)
{
	t_stk	*temp;

	if (*b != NULL && (*b)->next != NULL)
	{
		temp = *b;
		*b = (*b)->next;
		temp->next = (*b)->next;
		(*b)->next = temp;
	}
}
//Does sa + sb at the same time
void	ss(t_stk **a, t_stk **b)
{
	sa(a);
	sb(b);
}
