/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:37:26 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/03/28 18:56:12 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_swap(t_push *push, char **av)
{   

/*     duplicate_nums(push->split);
    is_nums(&push->split[1]); */

    put_arg_to_int(push, av);
}

int main(int ac, char **av)
{
    t_push *push;
    
    push = NULL;
    if (ac < 2)
        exit_ps("need-aarg");
    else
        {
            push = ft_init_push(push);
            push_swap(push, av);
            push = NULL;
        }
    
}