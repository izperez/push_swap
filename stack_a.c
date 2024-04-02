/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:49:14 by izperez           #+#    #+#             */
/*   Updated: 2024/04/02 15:07:53 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	set_index(t_psl *list)
{
	t_stack *current;
	int		i;
	int		mid;

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

void	set_target_a(t_psl *a, t_psl *b)
{
	t_stack	*current;

	current = a->first;
	while(1)
	{
		current->target = max_num(b, current->n);
		printf("target: %i\n", current->target->n);
		current = current->next;
		if (current == a->first)
			break ;
	}
}

void	set_price(t_psl *a, t_psl *b)
{
	t_stack	*current;

	current = a->first;
	while (1)
	{
		if (((current->above_median == 1 && current->target->above_median == 1) && \
		(current->i == current->target->i)) || \
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
			if (current->above_median == 1)
				current->price = current->i;
			else
				current->price = stack_len(a) - current->i;
		
			if (current->target->above_median == 1)
				current->price += current->target->i;
			else
				current->price += stack_len(b) - current->target->i;
		}
			current = current->next;
		if (current == a->first)
			break ;
	}
}

void	stack_a(t_psl *a, t_psl *b)
{
	set_index(a);
	set_index(b);
	set_target_a(a, b);
	set_price(a, b);
	//set_cheapest(a);
	// to_push();
}
