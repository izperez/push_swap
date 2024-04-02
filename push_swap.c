/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:14:43 by izperez           #+#    #+#             */
/*   Updated: 2024/04/02 12:20:06 by izperez          ###   ########.fr       */
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

static void	print_stack(t_psl *list)
{
	t_stack	*current;

	if (list == NULL || list->first == NULL)
		return ;
	current = list->first;
	while (current != NULL)
	{
		ft_printf("%d\n", current->n);
		//ft_printf("prev: %d\nnext:%d\n", current->prev->n, current->next->n);
		if (current->next == list->first)	
			break ;
		current = current->next;
	}
}

int	main(int ac, char **av)
{
	t_psl	*a;
	t_psl	*b;
	t_stack *current;

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
	b = init_stack_b(a);
	if (stack_len(a) == 3)
		sorting_three(a);

	current = a->first;
	
	while(1)
	{
		printf("target de a %i, es %i\n", current->n, max_num(b, current->n)->n);
		current = current->next;
		if (current == a->first)
			break ;
		
	}
	printf("******* Stack A *******\n");
	print_stack(a);
	printf("******* Stack B *******\n");
	print_stack(b);
} 
