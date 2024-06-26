/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:16:58 by izperez           #+#    #+#             */
/*   Updated: 2024/05/01 11:59:30 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# include "../libft/libft.h"

//checker_aux.c
int		stack_len(t_psl *stack);
t_psl	*append_node(t_psl *list, int i);
t_psl	*init_stack_a(t_psl *list, char **av);
t_psl	*init_stack_b(void);
void	free_stack(t_psl *stack);

//checker_auxiliar.c
void	push_swap(int ac, char **av);

#endif