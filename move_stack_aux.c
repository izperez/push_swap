/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_a_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:14:26 by izperez           #+#    #+#             */
/*   Updated: 2024/04/05 13:17:08 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_both(t_psl *a, t_psl *b)
{
	while (a->first->cheapest != 1 && b->first->cheapest != 1)
		rrr(a, b);
	set_index(a);
	set_index(b);
}

static void	rotate_both(t_psl *a, t_psl *b)
{
	while (a->first->cheapest != 1 && b->first->cheapest != 1)
		rr(a, b);
	set_index(a);
	set_index(b);
}

/* Move other (rb) */
static	void	move_other_aux(t_psl *list, t_stack *node)
{
	if (node->above_median == 1)
	{
		while (list->first != node)
			rb(list);
	}
	else
	{
		while (list->first != node)
			rrb(list);
	}
}

/*  We have one node at the top of the stack. Now we move the other.
 *  (ra)*/
static void	move_other(t_psl *list, t_stack *node, int mode)
{
	if (mode == 1)
	{
		if (node->above_median == 1)
		{
			while (list->first != node)
				ra(list);
		}
		else
		{
			while (list->first != node)
				rra(list);
		}
	}
	else
	{
		move_other_aux(list, node);
	}
}

/* Moves at least one node at the top of the stack */
void	move_one_top(t_psl *a, t_psl *b)
{
	t_stack	*current;
	t_stack	*cheapest;

	current = a->first;
	if (current->above_median == 1 && current->target->above_median == 1)
		rotate_both(a, b);
	if (current->above_median == 0 && current->target->above_median == 0)
		reverse_rotate_both(a, b);
	cheapest = get_cheapest(a);
	move_other(a, cheapest, 1);
	move_other(b, cheapest->target, 2);
	pb(a, b);
}
