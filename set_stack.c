/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:08:10 by izperez           #+#    #+#             */
/*   Updated: 2024/04/08 12:52:21 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Set the index */
void	set_index(t_psl *list)
{
	t_stack	*current;
	int		i;
	int		mid;

	if (list->first == NULL)
		return ;
	mid = stack_len(list) / 2;
	current = list->first;
	i = 0;
	while (1)
	{
		current->i = i;
		if (i < mid)
			current->above_median = 1;
		else
			current->above_median = 0;
		current = current->next;
		i++;
		if (current == list->first)
			break ;
	}
}

/* Set the target for each value */
void	set_target_a(t_psl *a, t_psl *b)
{
	t_stack	*current;

	current = a->first;
	while (1)
	{
		current->target = max_num(b, current->n);
		current = current->next;
		if (current == a->first)
			break ;
	}
}

//set price (b)
static void	set_price_aux(t_psl *a, t_psl *b)
{
	t_stack	*current;

	current = a->first;
	if (current->above_median == 1)
		current->price = current->i;
	else
		current->price = stack_len(a) - current->i;
	if (current->target->above_median == 1)
		current->price += current->target->i;
	else
		current->price += stack_len(b) - current->target->i;
}

/* Set the price for each value (a)*/
void	set_price(t_psl *a, t_psl *b)
{
	t_stack	*current;

	current = a->first;
	while (1)
	{
		if (((current->above_median == 1 && current->target->above_median == 1) \
		&& (current->i == current->target->i)) || \
		((current->above_median == 0 && current->target->above_median == 0) && \
		((stack_len(b) - current->target->i) == (stack_len(a) - current->i))))
		{
			if (current->above_median == 1)
				current->price = current->i;
			else
				current->price = stack_len(a) - current->i;
		}
		else
		{
			set_price_aux(a, b);
		}
		current = current->next;
		if (current == a->first)
			break ;
	}
}

/* Set the cheapest node */
void	set_cheapest(t_psl *list)
{
	t_stack	*current;
	int		min;

	min = INT_MAX;
	current = list->first;
	while (1)
	{
		if (current->price < min)
			current->cheapest = 1;
		if (current == list->first)
			break ;
	}
}
