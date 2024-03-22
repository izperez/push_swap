/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:17:38 by izperez           #+#    #+#             */
/*   Updated: 2024/03/22 12:24:44 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define LONG_MAX 9223372036854775807
# define LONG_MIN -2147483647

# define ERROR "\033[1;31m[Error]\033[0m\n"

# define PA "\033[35mpa\033[0m\n"
# define PB "\033[35mpb\033[0m\n"
# define SA "\033[35msa\033[0m\n"
# define SB "\033[35msb\033[0m\n"
# define SS "\033[35mss\033[0m\n"
# define RA "\033[35mra\033[0m\n"
# define RB "\033[35mrb\033[0m\n"
# define RR "\033[35mrr\033[0m\n"
# define RRA "\033[35mrra\033[0m\n"
# define RRB "\033[35mrrb\033[0m\n"
# define RRR "\033[35mrrr\033[0m\n"

typedef struct s_stack
{
	int				n;
	int				i;
	int				price;
	int				above_median;
	int				cheapest;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}				t_stk;


//init_stack_a.c
void	init_stack_a(t_stk **a, char **av);

//errors.c
int		error_syntax(char **av);

#endif
