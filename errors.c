/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:06:09 by izperez           #+#    #+#             */
/*   Updated: 2024/03/22 14:12:37 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char **av)
{
	int	i;
	int j;
	// int	n;

	i = 0;
	while (av[i] != NULL)
	{
		j = 0;
		// printf("--%s\n", av[i]);
		while (av[i][j] != '\0')
		{
			if (av[1][j] == '-' && j == 0)
				j++;
			if (!ft_isdigit(av[i][j]) && !(av[i][j] == '-'))
			{
				printf("Error\n");
				return(0);
			}
			j++;
		}
		i++;
	}
	return (1);
}