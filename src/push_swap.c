/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:37:26 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/03 13:10:50 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    push_swap(t_stack **stack, char **av, t_push *push)
{   
    put_arg_to_int(*stack, av, push);
}

int main(int ac, char **av)
{
    t_push *push;
    t_stack *a;
   
    a = NULL;
    push = NULL;
    if (ac < 2)
        exit_ps("need-arg");
    else
        {
            push = ft_init_push(push);
            push_swap(&a, av, push);
            //printf("%d", a->content);
            algo_2(a, push);
        }
    return (0);
    
}