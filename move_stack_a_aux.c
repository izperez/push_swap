/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_a_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:14:26 by izperez           #+#    #+#             */
/*   Updated: 2024/04/04 13:20:36 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_cheapest(t_psl *list)
{
	t_stack	*current;

	current = list->first;
	while (1)
	{
		if (current->cheapest == 1)
			return (current);
		current = current->next;
		if (current == list->first)
			break ;
	}
	return (current);
}

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
}

static void	move_one_top(t_psl *a, t_psl *b)
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
void	push_from_a(t_psl *a, t_psl *b)
{
	int	len;
	int i;

	i = 0;
	len = stack_len(a);
	if (len == 5)
	{
		pb(a, b);
		pb(a, b);
	}
	if (len == 4)
		pb(a, b);
	len = stack_len(a);
	while (len > 3) //&& !//no esta ordenado)
	{
		stack_a(a, b);
		move_one_top(a, b);
		len = stack_len(a);
		// printf("******* Stack A *******\n");
		// print_stack(a);
		// printf("******* Stack B *******\n");
		// print_stack(b);
	}
	sorting_three(a);
}
