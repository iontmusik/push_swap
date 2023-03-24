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
    s_stack *a;
    s_stack *b;
    char    **split;
    int     len;
}   t_push;

#endif