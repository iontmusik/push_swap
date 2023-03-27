/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:37:26 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/03/27 15:37:32 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void free_ps(t_push *push)
// {

// }

t_push *ft_init_push(t_push *push)
{
    push = (t_push *)malloc(sizeof(t_push));
    if (push == NULL)
        exit(1);
    push->a = NULL;
    push->b = NULL;
    push->split = NULL;
    push->moves = 0;
    push->len = 0;
    push->len_a = 0;
    push->len_b = 0;
    return (push);
}







void    push_swap(t_push *push, char **av)
{   
    t_stack *stack;
    int i;

    i = 1;
    stack = NULL;
    push->split = ft_split(av[i], ' ');
    if (ft_checking(push->split, *push))
    {

    }
    free(push);
    
    printf("hola");
}

int main(int ac, char **av)
{
    t_push *push;
    
    push = NULL;
    if (ac < 2)
        exit(1);
    else
        {
            push = ft_init_push(push);
            push_swap(push, av);
            free(push);
            push = NULL;
        }
    
}