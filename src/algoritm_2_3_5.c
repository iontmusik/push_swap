/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_2_3_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:48:38 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/03 17:13:08 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    algo_2(t_stack **stack, t_push *push)
{
    t_stack *tmp;
    
    tmp = *stack;
    if (tmp->content > tmp->next->content)
        s_swap(stack, 'a', push);
}

/* void algo_3(t_stack **stack1, t_push *push)
{
	int num1;
	int num2;
	int	num3;
	
	num1 = 0;
	num2 = 0;
	num3 = 0;
	while (!(num1 < num2 && num2 < num3 && num1 < num3))
	{
		num1 = (*stack1)->content;
		num2 = (*stack1)->next->content;
		num3 = (*stack1)->next->next->content;	
		if ((num1 > num2 && num1 < num3 && num2 < num3) ||
			(num1 < num3 && num2 > num3 && num1 > num2) ||
			(num1 < num2 && num1 < num3 && num2 > num3))
			s_swap(stack1, 'a', push);
		if (num1 > num2 && num1 > num3 && num2 < num3)
			r_swap(stack1, 'a', push);
		if (num1 < num2 && num1 > num3 && num2 > num3)
			r_rev_swap(stack1, 'a', push);
	}
	
	return ;
} */

void algo_3(t_stack **stack1, t_push *push)
{
    int num1;
    int num2;
    int num3;
    
    num1 = (*stack1)->content;
    num2 = (*stack1)->next->content;
    num3 = (*stack1)->next->next->content;
    
    while (!(num1 < num2 && num2 < num3 && num1 < num3))
    {
        if ((num1 > num2 && num1 < num3 && num2 < num3) ||
            (num1 > num3 && num2 > num3 && num1 > num2) ||
            (num1 < num2 && num1 < num3 && num2 > num3))
            s_swap(stack1, 'a', push);
        if (num1 > num2 && num1 > num3 && num2 < num3)
            r_swap(stack1, 'a', push);
        if (num1 < num2 && num1 > num3 && num2 > num3)
            r_rev_swap(stack1, 'a', push);
        
        num1 = (*stack1)->content;
        num2 = (*stack1)->next->content;
        num3 = (*stack1)->next->next->content;
    }
}

