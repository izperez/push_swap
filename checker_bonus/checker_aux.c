/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:53:39 by izperez           #+#    #+#             */
/*   Updated: 2024/04/18 12:19:02 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* Function that free the stack */
void	free_stack(t_psl *stack)
{
	t_stack	*current;

	if (stack == NULL || stack->first == NULL)
		return ;
	current = stack->first;
	while (1)
	{
		current = current->next;
		free(current);
		if (current == stack->first)
			return ;
	}
	current = NULL;
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

int	stack_len(t_psl *stack)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = stack->first;
	while (1)
	{
		current = current->next;
		i++;
		if (current == stack->first)
			break ;
	}
	return (i);
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

	i = 1;
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
