/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:29:17 by izperez           #+#    #+#             */
/*   Updated: 2024/03/27 10:43:09 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//swap a: swap the first two elements from the stack_a.
//Does nothing if there is <= 1 element.
void	sa(t_psl *a)
{
	int	num;

	num = 0;
	if (a->first != NULL && a->first->next != NULL)
	{
		num = a->first->n;
		a->first->n = a->first->next->n;
		a->first->next->n = num;
	}
}

//swap b: Swap the first two elements from the stack_b.
//Does nothing if there is <= 1 element.
void	sb(t_psl *b)
{
	int num;

	num = 0;
	if (b->first != NULL && b->first->next != NULL)
	{
		num = b->first->n;
		b->first->n = b->first->next->n;
		b->first->next->n = num;
	}
}
//Does sa + sb at the same time
void	ss(t_psl *a, t_psl *b)
{
	sa(a);
	sb(b);
}
