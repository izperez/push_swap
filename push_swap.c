/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:14:43 by izperez           #+#    #+#             */
/*   Updated: 2024/05/01 11:49:25 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_psl *stack)
{
	int		i;
	t_stack	*current;

	i = 1;
	current = stack->first;
	while (current != stack->first->prev)
	{
		current = current->next;
		i++;
	}
	return (i);
}

/* Checks if the stack is sorted */
static int	stack_sorted(t_psl *stack)
{
	t_stack	*current;

	if (stack == NULL || stack->first == NULL)
		return (0);
	current = stack->first;
	while (1)
	{
		if (current->n > current->next->n && current->next != stack->first)
			return (0);
		current = current->next;
		if (current == stack->first)
			break ;
	}
	return (1);
}

/* Set the index */
void	set_index(t_psl *list)
{
	t_stack	*current;
	int		i;
	int		mid;

	if (list->first == NULL)
		return ;
	mid = (stack_len(list) / 2);
	current = list->first;
	i = 0;
	while (1)
	{
		current->i = i;
		if (i <= mid + 1)
			current->above_median = 1;
		else
			current->above_median = 0;
		current = current->next;
		i++;
		if (current == list->first)
			break ;
	}
}

void	free_array(char **result)
{
	int	j;

	j = 0;
	while (result[j])
	{
		free (result[j]);
		j++;
	}
	free (result);
}

int	main(int ac, char **av)
{
	t_psl	*a;
	t_psl	*b;
	char	**arg;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	else if (ac == 2)
		arg = ft_split(av[1], ' ');
	else
		arg = av + 1;
	if (error_syntax(arg) == 1)
		a = init_stack_a(a, arg);
	else
		return (0);
	b = init_stack_b();
	if (stack_sorted(a) == 1)
		exit (0);
	sorting_all(a, b);
	if (ac == 2)
		free_array(arg);
	free_stack(a);
	free(a);
}
