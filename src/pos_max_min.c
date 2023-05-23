/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_max_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:25:38 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/23 18:32:15 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pos_num_max(t_stack *stack, t_push *push, char c)
{
	push->posmax_a = 0;
	push->posmax_b = 0;
	ft_maximo(stack, push, c);
	if (c == 'a' && push->len_a != 0)
	{
		while (stack->content != push->max_a)
		{
			push->posmax_a++;
			stack = stack->next;
		}
	}
	if (c == 'b' && push->len_b != 0)
	{
		while (stack->content != push->max_b)
		{
			push->posmax_b++;
			stack = stack->next;
		}
	}
}

void	pos_num_min(t_stack *stack, t_push *push, char c)
{
	push->posmin_a = 0;
	push->posmin_b = 0;
	ft_minimo(stack, push, c);
	if (c == 'a' && push->len_a != 0)
	{
		while (stack->content != push->min_a)
		{
			push->posmin_a++;
			stack = stack->next;
		}
	}
	if (c == 'b' && push->len_b != 0)
	{
		while (stack->content != push->min_b)
		{
			push->posmin_b++;
			stack = stack->next;
		}
	}
}

void	posmaxmin(t_stack *stack, t_push *push, char c)
{
	pos_num_min(stack, push, c);
	pos_num_max(stack, push, c);
}
