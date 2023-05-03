/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_2_3_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:48:38 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/03 13:14:10 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    algo_2(t_stack **stack, t_push *push)
{
    t_stack *tmp;
    
    tmp = *stack;
    if (tmp->content > tmp->next->content)
        s_swap(*stack, 'a', push);
    printf("hola");
    //printf("%d\n", stack->content);
}