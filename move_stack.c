/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:49:14 by izperez           #+#    #+#             */
/*   Updated: 2024/04/06 12:42:40 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/* Main funtion: Prepares required values to push the cheapest node to b */
void	stack_a(t_psl *a, t_psl *b)
{
	set_index(a);
	set_index(b);
	set_target_a(a, b);
	set_price(a, b);
	set_cheapest(a);
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
		if (current->target)
			printf("target %i\n", current->target->n);
	}
}

/* Main funtion: Prepares required values to push form b to a */
void	stack_b(t_psl *a, t_psl *b)
{
	set_index(a);
	if (b)
	{
		set_index(b);
		set_target_b(a, b);
	}
}

/* Push from a to b */
void	sorting_all(t_psl *a, t_psl *b)
{
	int	len;
	int	i = 0;

	len = stack_len(a);
	if (len >= 5)
	{
		pb(a, b);
		pb(a, b);
	}
	else if (len >= 4)
		pb(a, b);
	len = stack_len(a);
	while (len > 3) //&& !//no esta ordenado)
	{
		stack_a(a, b);
		move_one_top(a, b);
		len = stack_len(a);
	}
	sorting_three(a);
	while (b->first)
	{
		stack_b(a, b);
		pa(a, b);
		printf("******* Stack A ******* %i\n", i);
		print_stack(a);
		printf("******* Stack B ******* %i\n", i);
		print_stack(b);
		i++;
	}
}
