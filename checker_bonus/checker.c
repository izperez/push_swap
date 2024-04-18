/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:17:02 by izperez           #+#    #+#             */
/*   Updated: 2024/04/18 12:11:11 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* Function that free the stack */
static void	free_stack(t_psl *stack)
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

/* Print error msg + free_stack() */
static void	error_free(t_psl *a, t_psl *b)
{
	ft_printf("Error\n");
	free_stack(a);
	free (b);
	// free_stack(b);
	exit(1);
}

/* Checks if the operation can be done */
static void	all_checked(t_psl *a, t_psl *b, char *str, int len)
{
	if (!ft_strncmp(str, "pa\n", len))
		pa(a, b);
	else if (!ft_strncmp(str, "pb\n", len))
		pb(a, b);
	else if (!ft_strncmp(str, "sa\n", len))
		sa(a);
	else if (!ft_strncmp(str, "sb\n", len))
		sb(b);
	else if (!ft_strncmp(str, "ss\n", len))
		ss(a, b);
	else if (!ft_strncmp(str, "ra\n", len))
		ra(a);
	else if (!ft_strncmp(str, "rb\n", len))
		rb(b);
	else if (!ft_strncmp(str, "rr\n", len))
		rr(a, b);
	else if (!ft_strncmp(str, "rra\n", len))
		rra(a);
	else if (!ft_strncmp(str, "rrb\n", len))
		rrb(b);
	else if (!ft_strncmp(str, "rrr\n", len))
		rrr(a, b);
	else
		error_free(a, b);
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

int	main(int ac, char **av)
{
	t_psl	*a;
	t_psl	*b;
	char	*line;
	int		len;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	a = init_stack_a(a, av);
	len = stack_len(a);
	line = get_next_line(STDIN_FILENO);
	b = init_stack_b();
	while (line)
	{
		all_checked(a, b, line, len);
		line = get_next_line(STDIN_FILENO);
	}
	if (b->size == 0)
	{
		free(b);
	}
	if (stack_sorted(a) == 1)
		ft_printf("OK\n");
	else
	{
		ft_printf("KO\n");
	}
	free_stack(a);
	exit(1);
}
