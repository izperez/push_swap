/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:06:09 by izperez           #+#    #+#             */
/*   Updated: 2024/03/22 12:39:14 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char **av)
{
	int	i;
	int	n;

	i = 0;
	while (av[1][i] != '\0')
	{
		n = ps_atol(av[1]);
		if (n > INT_MAX || n < INT_MIN)
			ft_printf("%s\n, Error, fuera del rango permitido.");
		else if ((av[1][i] > 32 && av[1][i] <= 47) ||
				(av[1][i] >= 58 && av[1][i] <= 126))
		{
			ft_printf("%s\n, Error, caracter no válido.");
			return (0);
		}
		i++;
	}
	return (1);
}
