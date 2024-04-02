/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:09:50 by izperez           #+#    #+#             */
/*   Updated: 2024/04/02 10:32:30 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max_num(t_psl *a)
{
	int	max;
	t_stack	*temp;

	max = a->first->n;
	temp = a->first->next;
	while (temp != a->first)
	{
		if (temp->n > max)
			max = temp->n;
		temp = temp->next;
	}
	return (max);
}

void	sorting_three(t_psl *a)
{
	int	max;

	max = max_num(a);
	while (a->first->n != max && a->first->next->n != max)
		ra(a);
	if (a->first->n == max)
		ra(a);
	else if (a->first->next->n == max)
		rra(a);
	if (a->first->n > a->first->next->n)
		sa(a);
}