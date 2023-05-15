/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_max_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:29:29 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/15 13:38:27 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_minimo(t_stack *stack, t_push *push, char c)
{
	push->min_a = 2147483647;
	push->min_b = 2147483647;
	if (c == 'a')
	{
		while (stack)
		{
			if (stack->content < push->min_a)
				push->min_a = stack->content;
			stack = stack->next;
		}
	}
	if (c == 'b')
	{
		while (stack)
		{
			if (stack->content < push->min_b)
				push->min_b = stack->content;
			stack = stack->next;
		}
	}
}

void	ft_maximo(t_stack *stack, t_push *push, char c)
{
	push->max_a = -2147483647;
	push->max_b = -2147483647;
	if (c == 'a')
	{
		while (stack)
		{
			if (stack->content > push->max_a)
				push->max_a = stack->content;
			stack = stack->next;
		}
	}
	if (c == 'b')
	{
		while (stack)
		{
			if (stack->content < push->max_b)
				push->max_b = stack->content;
			stack = stack->next;
		}
	}
}

void	maxminstack(t_stack *stack, t_push push, char c)
{
	ft_minimo(stack, &push, c);
	ft_maximmo(stack, &push, c);
}

void	count_nums(t_stack *stack, t_push *push, char c)
{
	maxminstack(stack, &push, c);
	
	if (c == 'a' && push->len_a != 0)
	{
		while (stack->content != push->len_a)
		{
			if (stack->content != push->len_a)
				push->len_a++;
			stack = stack->next;
		}
	}
	else if (c == 'b' && push->len_b != 0)
	{
		while (stack->content != push->len_b)
		{
			if (stack->content != push->len_b)
				push->len_b++;
			stack = stack->next;
		}
	}
}
