/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:38:14 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/03/29 13:51:52 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "./libft/libft.h"

typedef struct s_stack
{
    int             content;
    int             position;
    struct s_stack  *next;
}   t_stack;

typedef struct s_push
{
    t_stack *a;
    t_stack *b;
    char    **split;
    char    *fd;
    int     len;
    int     len_a;
    int     len_b;
    int     moves;
    int     cont_new;
}   t_push;

// INIT STRUCT  ARCHIVE: init.c
t_push      *ft_init_push(t_push *push);
void        put_arg_to_int(t_push *push, char **av);
t_stack	    *ft_lstnew_ps(int content);
void	    ft_lstadd_back_ps(t_stack **lst, t_stack *new);
void	    ft_lstadd_back_ps2(t_stack **lst, t_stack *new, t_push *push);
void        ft_order_lst(t_stack *a, t_stack *new);

// UTILS  ARCHIVE: push_swap_utils.c
t_stack	    *ft_lstlast_ps2(t_stack *lst, t_stack *new, t_push *push);
t_stack	    *ft_lstlast_ps(t_stack *lst);
void	    ft_lstiter_ps(t_stack *lst);

// CHECKING NUMS  ARCHIVE: checking.c
int         duplicate_nums(char **split);
int         int_limits(char *av);
long long   atoi_ps(char *num_char);
int         is_nums(char **av);

// EXIT ARCHIVE: exit.c
int         exit_ps(char *text);

// MOVEMENTS  ARCHIVE: movements.c
// SWAP: SA, SB, SS
void        s_swap(t_stack *stack, char c, t_push *push);
void        ss_swap(t_stack *a, t_stack *b, t_push *push);
// PUSH: PA, PB
void        p_swap(t_stack **stack1, t_stack **stack2, char c, t_push *push);
// ROTATE: RA, RB, RR
void        r_swap(t_stack **stack, char c, t_push *push);
void        rr_swap(t_stack **stack1, t_stack **stack2, t_push *push);
// ROTATE REVERSE: RRA, RRB, RRR
void        r_rev_swap(t_stack **stack, char c, t_push *push);
void        rr_rev_swap(t_stack **stack1, t_stack **stack2, t_push *push);




# define INT_MIN -2147483648
# define INT_MAX 2147483647


#endif