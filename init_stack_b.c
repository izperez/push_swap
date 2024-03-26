/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:55:39 by izperez           #+#    #+#             */
/*   Updated: 2024/03/26 10:12:28 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_b(t_stk **a, t_stk **b)
{
	if (*a == NULL)
		return ;
	if ((*a)->next != NULL)
	{
		pb(a, b);
		pb(a, b);
	}
	// printf("******* Stack B *******\n");
	// print_stack(*b);
}