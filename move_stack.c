/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:49:14 by izperez           #+#    #+#             */
/*   Updated: 2024/04/11 12:02:34 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	final_rotation(t_psl *a)
{
	t_stack	*mini;

	mini = min_num(a, INT_MIN);
	while (mini != a->first)
	{
		if (mini->above_median == 1)
			ra(a);
		else
			rra(a);
	}
}

/* Returns the cheapest node */
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

void	set_target_b(t_psl *a, t_psl *b)
{
	t_stack	*current;

	current = b->first;
	while (1)
	{
		current->target = min_num(a, current->n);
		current = current->next;
		if (current == b->first)
			break ;
	}
}

/* Push from a to b */
void	sorting_all(t_psl *a, t_psl *b)
{
	int	len;

	len = stack_len(a);
	if (len >= 5)
	{
		pb(a, b);
		pb(a, b);
	}
	else if (len >= 4)
		pb(a, b);
	len = stack_len(a);
	while (len > 3)
	{
		stack_a(a, b);
		move_one_top_a(a, b);
		len = stack_len(a);
	}
	sorting_three(a);
	while (b->first)
	{
		stack_b(a, b);
		move_one_top_b(b, a);
	}
	final_rotation(a);
}
