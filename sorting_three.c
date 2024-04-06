/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:09:50 by izperez           #+#    #+#             */
/*   Updated: 2024/04/06 11:22:31 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*min_num(t_psl *list, int deli)
{
	int		min;
	t_stack	*min_node;
	t_stack	*temp;

	min_node = NULL;
	min = INT_MAX;
	temp = list->first;
	while (1)
	{
		if (temp->n < min && temp->n > deli)
		{
			min_node = temp;
			min = temp->n;
		}
		if (min == INT_MIN)
			min_node = min_num(list, INT_MIN);
		temp = temp->next;
		if (temp == list->first)
			break ;
	}
	return (min_node);
}

t_stack	*max_num(t_psl *list, int deli)
{
	int		max;
	t_stack	*max_node;
	t_stack	*temp;

	max_node = NULL;
	max = INT_MIN;
	temp = list->first;
	while (1)
	{
		if (temp->n > max && temp->n < deli)
		{
			max_node = temp;
			max = temp->n;
		}
		if (max == INT_MIN)
			max_node = max_num(list, INT_MAX);
		temp = temp->next;
		if (temp == list->first)
			break ;
	}
	return (max_node);
}

void	sorting_three(t_psl *a)
{
	int	max;

	max = max_num(a, INT_MAX)->n;
	while (a->first->n != max && a->first->next->n != max)
		ra(a);
	if (a->first->n == max)
		ra(a);
	else if (a->first->next->n == max)
		rra(a);
	if (a->first->n > a->first->next->n)
		sa(a);
}
