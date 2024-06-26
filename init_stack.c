/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:01:50 by izperez           #+#    #+#             */
/*   Updated: 2024/05/01 10:58:00 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/* Main funtion: Prepares required values to push the cheapest node to b */
void	stack_a(t_psl *a, t_psl *b)
{
	set_index(a);
	set_index(b);
	set_target_a(a, b);
	set_price(a, b);
	set_cheapest(a);
}

/* Function that initializes the stack */
t_psl	*init_stack_b(void)
{
	t_psl	*b;

	b = malloc(sizeof(t_psl));
	if (b == NULL)
		return (NULL);
	b->first = NULL;
	b->last = NULL;
	b->size = 0;
	return (b);
}

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
	new_node->next = NULL;
	new_node->prev = list->last;
	new_node->target = NULL;
	list->cheapest = NULL;
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
	list->size = 0;
	while (av[i] != NULL)
	{
		n = ps_atol(av[i]);
		list = append_node(list, i);
		list->size++;
		if (list == NULL)
			return (NULL);
		list->last->n = n;
		i++;
	}
	return (list);
}
