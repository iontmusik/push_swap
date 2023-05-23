/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:38:14 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/20 16:47:58 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "../libft/libft.h"
# include "printf.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	int				pos;
}	t_stack;

typedef struct s_push
{
/* 	t_stack	*a;
	t_stack	*b; */
	char	**split;
	int		len_a;
	int		len_b;
	int		posmax_a;
	int		posmin_a;
	int		posmax_b;
	int		posmin_b;
	int		max_a;
	int		max_b;
	int		min_a;
	int		min_b;
	int		moves;
}	t_push;

// INIT STRUCT  ARCHIVE: init.c
void		ft_init_push(t_push *push);

// UTILS   ARCHIVE: push_swap_utils.c  push_swap_utils2.c
void		put_arg_to_int(t_stack **stack, int num);
t_stack		*ft_lstnew_ps(int content);
void		ft_lstadd_back_ps(t_stack **lst, t_stack *new);
void		ft_order_lst(t_stack *a, t_stack *new);
void		position_nums(t_stack *stack, t_stack *new);
void		ft_lstorder(t_stack **stack_a);
void		stackclear(t_stack **stack_a);
int			ft_lstsize_ps(t_stack *lst);

// UTILS  ARCHIVE: push_swap_utils.c
t_stack		*ft_lstlast_ps(t_stack *lst);
void		ft_lstiter_ps(t_stack *lst);

// PRINT MOVEMENTS  ARCHIVE: print_moves.c
void		print_and_moves_s(t_push *push, char c);
void		print_and_moves_p(t_push *push, char c);
void		print_and_moves_r(t_push *push, char c);
void		print_and_moves_w(t_push *push, char c);

// MAX NUM & MIN NUM & COUNT NUMS ARCHIVE count_max_min.c
void		maxminstack(t_stack *stack, t_push *push, char c);
int			count_nums(t_stack *stack);
void		ft_maximo(t_stack *stack, t_push *push, char c);
void		ft_minimo(t_stack *stack, t_push *push, char c);
void		pos_num_min(t_stack *stack, t_push *push, char c);
void		pos_num_max(t_stack *stack, t_push *push, char c);
void		posmaxmin(t_stack *stack, t_push *push, char c);

// POS MAX NUM & POS MIN NUM   ARCHIVE: pos_max_min.c
void		posmaxmin(t_stack *stack, t_push *push, char c);

// CHECKING NUMS  ARCHIVE: checking.c
void		duplicate_nums(t_stack *stack, int num);
void		argcheck(char **argv, t_stack **stack_a);

// MOVEMENTS  ARCHIVE: movements.c movements2.c
// SWAP: SA, SB, SS
void		sa_swap(t_stack **stack_a, t_push *push);
void		sb_swap(t_stack **stack_b, t_push *push);
void		ss_swap(t_stack **stack_a, t_stack **stack_b, t_push *push);
// PUSH: PA, PB
void		pa_swap(t_stack **stacka, t_stack **stackb, t_push *push);
void		pb_swap(t_stack **stacka, t_stack **stackb, t_push *push);
// ROTATE: RA, RB, RR
void		ra_swap(t_stack **stack, t_push *push);
void		rb_swap(t_stack **stack, t_push *push);
void		rr_swap(t_stack **stack1, t_stack **stack2, t_push *push);
void		ra_rra(t_stack **stack_a, t_push *push, int pos);
// ROTATE REVERSE: RRA, RRB, RRR
void		r_reva_swap(t_stack **stack_a, t_push *push);
void		r_revb_swap(t_stack **stack_b, t_push *push);
void		rr_rev_swap(t_stack **stack1, t_stack **stack2, t_push *push);

// ALGORITHMS
void		algo_2(t_stack **stack, t_push *push);
void		algo_3(t_stack **stack1, t_push *push);
void		algo_5(t_stack **stack_a, t_stack **stack_b, t_push *push);
void		radix_sort(t_stack **stack_a, t_stack **stack_b, t_push *push);
void		ft_move_a(t_stack **stack_a, t_stack **stack_b, t_push *push);
void		select_algo(t_stack **stack_a, t_stack **stack_b, t_push *push);

// EXIT ARCHIVE: exit.c
void		ft_freestr(char **str);
#endif