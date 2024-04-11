/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:06:09 by izperez           #+#    #+#             */
/*   Updated: 2024/04/09 11:00:05 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_duplicated(char **av, int len)
{
	int		i;
	int		j;
	long	num;

	i = 0;
	while (i < len)
	{
		num = ps_atol(av[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			ft_printf("Error, number out of range\n");
			exit (0);
		}
		j = i + 1;
		while (j < len)
		{
			if (num == ps_atol(av[j]))
			{
				ft_printf("Error, duplicated number\n");
				exit (0);
			}
			j++;
		}
		i++;
	}
}

static void	error_syntax_aux(char **av, int i, int j)
{
	while (av[i][j] == ' ')
		j++;
	if (av[i][j] == '\0' || av[i][j] == '+')
		i++;
	if (av[i][0] == '\0' ||
	(av[i][0] == '-' && av[i][j] != ' ' && av[i][1] == '\0') || av[i][0] == '+')
	{
		ft_printf("Error, Invalid number\n");
		return ;
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
		while (av[i][j] != '\0')
		{
			if (!ft_isdigit(av[i][j]) && !(av[i][j] == '-' && j == 0)
			&& !(av[i][j] == '+'))
			{
				printf("Error, pepito\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	check_duplicated(av, i);
	return (1);
}
