/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:35:21 by izperez           #+#    #+#             */
/*   Updated: 2024/04/05 13:05:11 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_psl *list)
{
	list->first = list->first->prev;
	list->last = list->last->prev;
}

/* rra: Moves downwards all the element of stack_a one pos
 * The last node becomes first */
void	rra(t_psl *a)
{
	reverse_rotate(a);
	ft_printf("RRA\n");
}

/* rrb: Moves downwards all the element of stack_b one pos
 * The last node becomes first */
void	rrb(t_psl *b)
{
	reverse_rotate(b);
	ft_printf("RRB\n");
}

//rra + rrb at the same time
void	rrr(t_psl *a, t_psl *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("RRR\n");
}
