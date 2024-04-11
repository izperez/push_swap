/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:13:25 by izperez           #+#    #+#             */
/*   Updated: 2024/04/11 12:08:49 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_psl *list)
{
	list->first = list->first->next;
	list->last = list->last->next;
}

/* rotate a: Moves uppwards all the elements of stack_a one pos
 * the first element becomes the last. */
void	ra(t_psl *a)
{
	rotate(a);
	ft_printf("ra\n");
}

/* rotate b: Moves uppwards all the elements of stack_b one pos
 * the first element becomes the last. */
void	rb(t_psl *b)
{
	rotate(b);
	ft_printf("rb\n");
}

//ra + rb at the same time
void	rr(t_psl *a, t_psl *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
