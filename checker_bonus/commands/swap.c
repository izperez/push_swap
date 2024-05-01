/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:29:17 by izperez           #+#    #+#             */
/*   Updated: 2024/05/01 11:57:41 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_psl *list)
{
	int	num;

	num = 0;
	if (list->first != NULL && list->first->next != NULL)
	{
		num = list->first->n;
		list->first->n = list->first->next->n;
		list->first->next->n = num;
	}
}

//swap a: swap the first two elements from the stack_a.
//Does nothing if there is <= 1 element.
void	sa(t_psl *a)
{
	swap(a);
}

//swap b: Swap the first two elements from the stack_b.
//Does nothing if there is <= 1 element.
void	sb(t_psl *b)
{
	swap(b);
}

//Does sa + sb at the same time
void	ss(t_psl *a, t_psl *b)
{
	swap(a);
	swap(b);
}
