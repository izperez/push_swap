/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:17:38 by izperez           #+#    #+#             */
/*   Updated: 2024/04/09 10:25:53 by izperez          ###   ########.fr       */
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

typedef struct s_psl
{
	struct s_stack			*first;
	struct s_stack			*last;
	int						size;
}				t_psl;

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
}				t_stack;

//push_swap.c
int		stack_len(t_psl *stack);
void	print_stack(t_psl *list);

//init_stack.c
t_psl	*init_stack_a(t_psl *a, char **av);
t_psl	*init_stack_b(void);
void	stack_a(t_psl *a, t_psl *b);
void	stack_b(t_psl *a, t_psl *b);

//errors.c
int		error_syntax(char **av);

//commands
void	pa(t_psl *a, t_psl *b);
void	pb(t_psl *a, t_psl *b);
void	sa(t_psl *a);
void	sb(t_psl *b);
void	ss(t_psl *a, t_psl *b);
void	ra(t_psl *a);
void	rb(t_psl *b);
void	rr(t_psl *a, t_psl *b);
void	rra(t_psl *a);
void	rrb(t_psl *b);
void	rrr(t_psl *a, t_psl *b);

//shorting_three.c
void	sorting_three(t_psl *a);
t_stack	*min_num(t_psl *list, int deli);
t_stack	*max_num(t_psl *list, int deli);
void	reverse_rotate_both(t_psl *a, t_psl *b);
void	rotate_both(t_psl *a, t_psl *b);

//move_stack.c
t_stack	*get_cheapest(t_psl *list);
void	set_target_b(t_psl *a, t_psl *b);

void	sorting_all(t_psl *a, t_psl *b);

//move_stack_aux.c
void	move_one_top_a(t_psl *a, t_psl *b);
void	move_one_top_b(t_psl *b, t_psl *a);

//set_stack.c
void	set_index(t_psl *list);
void	set_target_a(t_psl *a, t_psl *b);
void	set_price(t_psl *a, t_psl *b);
void	set_cheapest(t_psl *list);

#endif
