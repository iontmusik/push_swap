/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:38:14 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/16 13:53:28 by jtorre-s         ###   ########.fr       */
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

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	int				pos;
}	t_stack;

typedef struct s_push
{
	t_stack	*a;
	t_stack	*b;
	char	**split;
	char	*fd;
	int		len;
	int		len_a;
	int		len_b;
	int		max_a;
	int		max_b;
	int		min_a;
	int		min_b;
	int		moves;
	int		cont_new;
}	t_push;

// INIT STRUCT  ARCHIVE: init.c
t_push		*ft_init_push(t_push *push);
void		put_arg_to_int(t_stack **stack, char **av, t_push *push);
t_stack		*ft_lstnew_ps(int content);
void		ft_lstadd_back_ps(t_stack **lst, t_stack *new);
void		ft_order_lst(t_stack *a, t_stack *new);
void		position_nums(t_stack *stack, t_stack *new);

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
void		count_nums(t_stack *stack, t_push *push, char c);

// CHECKING NUMS  ARCHIVE: checking.c
int			duplicate_nums(char **split);
int			int_limits(char *av);
long long	atoi_ps(char *num_char);
int			is_nums(char **av);

// EXIT ARCHIVE: exit.c
int			exit_ps(char *text);

// MOVEMENTS  ARCHIVE: movements.c
// SWAP: SA, SB, SS
void		s_swap(t_stack **stack, char c, t_push *push);
void		ss_swap(t_stack *a, t_stack *b, t_push *push);
// PUSH: PA, PB
void		p_swap(t_stack **stack1, t_stack **stack2, char c, t_push *push);
// ROTATE: RA, RB, RR
void		r_swap(t_stack **stack, char c, t_push *push);
void		rr_swap(t_stack **stack1, t_stack **stack2, t_push *push);
// ROTATE REVERSE: RRA, RRB, RRR
void		r_rev_swap(t_stack **stack, char c, t_push *push);
void		rr_rev_swap(t_stack **stack1, t_stack **stack2, t_push *push);

// ALGORITHMS
void		algo_2(t_stack **stack, t_push *push);
void		algo_3(t_stack **stack1, t_push *push);

# define INT_MIN -2147483648
# define INT_MAX 2147483647

#endif