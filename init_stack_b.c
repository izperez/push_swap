/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:55:39 by izperez           #+#    #+#             */
/*   Updated: 2024/03/26 15:11:23 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_psl	*init_stack_b(t_psl *a)
{
	t_psl	*b;
	if (a->first == NULL)
		return (NULL);
	b = (t_psl *)malloc(sizeof(t_psl));
	if (b == NULL)
		return (NULL);
	b->first = NULL;
	if (a->first->next != NULL)
	{
		pb(a, b);
		pb(a, b);
	}
	return (b);
}
