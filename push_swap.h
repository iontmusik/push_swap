/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:38:14 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/03/24 16:33:09 by jtorre-s         ###   ########.fr       */
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
    struct s_stack  *next;
    struct s_stack  *prev;
}   t_stack;

typedef struct s_push
{
    t_stack *a;
    t_stack *b;
    char    **split;
    char    *fd;
    int     len;
}   t_push;

int     ft_checking(char **split, t_push push);
int     duplicate_nums(char **split);
int     int_limits(char *av);

#endif