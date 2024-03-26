/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:01:50 by izperez           #+#    #+#             */
/*   Updated: 2024/03/26 12:51:41 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Function wich appends all nodes required */
t_psl	*append_node(t_psl *list, int i)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->n = 0;
	new_node->i = i;
	new_node->above_median = 0;
	new_node->cheapest = 0;
	new_node->next = NULL;
	new_node->prev = list->last;
	new_node->target = NULL;
	if (list->first == NULL)
		list->first = new_node;
	else
		list->last->next = new_node;
	list->last = new_node;
	list->first->prev = list->last;
	list->last->next = list->first;
	return (list);
}

/* Function that initializes the stack */
t_psl	*init_stack_a(t_psl *list, char **av)
{
	int		i;
	int		n;

	i = 0;
	list = malloc(sizeof(t_psl));
	if (list == NULL)
		return (NULL);
	list->first = NULL;
	list->last = NULL;
	while (av[i] != NULL)
	{
		n = ps_atol(av[i]);
		list = append_node(list, i);
		if (list == NULL)
			return (NULL);
		list->last->n = n;
		i++;
	}
	return (list);
}
