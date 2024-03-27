/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:35:21 by izperez           #+#    #+#             */
/*   Updated: 2024/03/27 13:08:39 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* rra: Moves downwards all the element of stack_a one pos
 * The last node becomes first */
void	rra(t_psl *a)
{
	a->first = a->first->prev;
	a->last = a->last->next;
}

/* rrb: Moves downwards all the element of stack_b one pos
 * The last node becomes first */
void	rrb(t_psl *b)
{
	b->first = b->first->prev;
	b->last = b->last->next;
}

//rra + rrb at the same time
void	rrr(t_psl *a, t_psl *b)
{
	rra(a);
	rrb(b);
}