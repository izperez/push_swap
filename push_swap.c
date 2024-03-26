/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:14:43 by izperez           #+#    #+#             */
/*   Updated: 2024/03/26 15:16:02 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_psl *list)
{
	t_stack	*current;

	current = list->first;
	if (list == NULL)
		return ;
	else
	{
		ft_printf("%d\n", current->n);
		current = current->next;
	}
	while (list->first != current)
	{
		ft_printf("%d\n", current->n);
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
	b = init_stack_b(a);
	printf("******* Stack A *******\n");
	print_stack(a);
	printf("******* Stack B *******\n");
	print_stack(b);
} 
