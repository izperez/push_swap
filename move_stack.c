/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:49:14 by izperez           #+#    #+#             */
/*   Updated: 2024/04/08 13:10:23 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* 
void	all_sorted(t_psl *a)
{
	t_stack	*mini;

	mini = min_num(a, INT_MAX);
	a->first = mini;
	a->first->prev = mini->prev;
} */

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
	t_stack	*cheap;

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
	cheap = min_num(a, INT_MIN);
	a->first = cheap;
	a->first->prev = cheap->prev;
}
