/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:14:43 by izperez           #+#    #+#             */
/*   Updated: 2024/03/22 14:08:09 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stk *stack)
{
	t_stk	*current;

	current = stack;
	while (current != NULL)
	{
		ft_printf("%d\n", current->n);
		current = current->next;
	}
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	t_stk	*a;
	t_stk	*b;
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
		init_stack_a(&a, arg);
	print_stack(a);
}
