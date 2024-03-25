/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:01:50 by izperez           #+#    #+#             */
/*   Updated: 2024/03/25 10:19:03 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Function wich appends all nodes required */
t_stk	*append_node(t_stk	*top_node, int i)
{
	t_stk	*new_node;
	t_stk	*last_node;

	//crear un nuevo nodo
	new_node = malloc(sizeof(t_stk));
	if (new_node == NULL)
		return (0);
	//Inicializar los valores del nodo
	new_node->n = 0;
	new_node->i = i;
	new_node->above_median = 0;
	new_node->cheapest = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->target = NULL;
	//si la lista esta vacia, el nuevo nodo se añade
	if (top_node == NULL)
		return (new_node);
	//encontrar el último nodo de la lista
	last_node = top_node;
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}
	//añadir el nuevo nodo al final de la lista
	last_node->next = new_node;
	new_node->prev = last_node;
	//devuelve el nuevo nodo
	return (new_node);
	free (new_node);
}

/* Function that initializes the stack */
void	init_stack_a(t_stk **a, char **av)
{
	int	i;
	int	n;
	t_stk	*start = NULL;

	i = 0;
	//Agrega cada num en av al stack
	while (av[i] != NULL)
	{
		n = ps_atol(av[i]);
		*a = append_node(*a, i);
		if (start == NULL)
			start = *a;
		(*a)->n = n;
		i++;
	}
	*a = start;
}