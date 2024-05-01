/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:06:09 by izperez           #+#    #+#             */
/*   Updated: 2024/05/01 11:53:33 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	check_duplicated(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i] != NULL)
	{
		j = i + 1;
		while (av[j] != NULL)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				ft_putstr_fd("Error, duplicated\n", 2);
				exit (0);
			}
			j++;
		}
		i++;
	}
}

static void	error_syntax_aux(char **av, int i, int j)
{
	if (av[i][j] == '-' || av[i][j] == '+')
	{
		j++;
		if (av[i][j] == '\0')
		{
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
	}
	while (av[i][j] != '\0')
	{
		if (!ft_isdigit(av[i][j]) && av[i][j] != '\0')
		{
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
		j++;
	}
	if ((ps_atol(av[i]) > INT_MAX) || (ps_atol(av[i]) < INT_MIN)
		|| av[i][0] == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
}

int	error_syntax(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i] != NULL)
	{
		j = 0;
		error_syntax_aux(av, i, j);
		i++;
	}
	check_duplicated(av);
	return (1);
}
