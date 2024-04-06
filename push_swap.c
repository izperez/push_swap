/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:14:43 by izperez           #+#    #+#             */
/*   Updated: 2024/04/06 12:42:58 by izperez          ###   ########.fr       */
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

void	print_stack(t_psl *list)
{
	t_stack	*current;

	if (list == NULL || list->first == NULL)
		return ;
	current = list->first;
	while (current != NULL)
	{
		// ft_printf("dir value: %p\n", current);
		// ft_printf("next dir value: %p\n", current->next);
		// ft_printf("prev dir value: %p\n", current->prev);
		ft_printf("%d\n", current->n);
		// ft_printf("index: %d\n", current->i);
		// ft_printf("price: %i\n", current->price);
		// ft_printf("cheapest: %i\n", current->cheapest);
		// if (current->target)
		// 	ft_printf("target: %i\n", current->target->n);
		// ft_printf("\n\n");
		if (current->next == list->first)
			break ;
		current = current->next;
	}
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
	b = init_stack_b();
	if (stack_len(a) == 3)
		sorting_three(a);
	sorting_all(a, b);
	printf("******* Stack A *******\n");
	print_stack(a);
	printf("******* Stack B *******\n");
	print_stack(b);
}
