/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:13:25 by izperez           #+#    #+#             */
/*   Updated: 2024/03/27 13:08:18 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* rotate a: Moves uppwards all the elements of stack_a one pos
 * the first element becomes the last. */
void	ra(t_psl *a)
{
	a->first = a->first->next;
	a->last = a->last->prev;
}
/* rotate b: Moves uppwards all the elements of stack_b one pos
 * the first element becomes the last. */
void	rb(t_psl *b)
{
	b->first = b->first->next;
	b->last = b->last->prev;
}

//ra + rb at the same time
void	rr(t_psl *a, t_psl *b)
{
	ra(a);
	rb(b);
}