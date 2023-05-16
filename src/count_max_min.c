/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_max_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:29:29 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/16 13:03:00 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_minimo(t_stack *stack, t_push *push, char c)
{
	push->min_a = INT_MAX;
	push->min_b = INT_MAX;
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

static void	ft_maximo(t_stack *stack, t_push *push, char c)
{
	push->max_a = INT_MIN;
	push->max_b = INT_MIN;
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

void	maxminstack(t_stack *stack, t_push *push, char c)
{
	ft_minimo(stack, push, c);
	ft_maximo(stack, push, c);
}

void	count_nums(t_stack *stack, t_push *push, char c)
{
	maxminstack(stack, push, c);
	if (c == 'a' && stack)
	{
		while (stack)
		{
			push->len_a++;
			stack = stack->next;
		}
	}
	else if (c == 'b' && stack)
	{
		while (stack)
		{
			push->len_b++;
			stack = stack->next;
		}
	}
}

void	position_nums(t_stack *stack, t_stack *new)
{
	while (stack)
	{
		if (new->content > stack->content)
			new->pos++;
		else if (new->content < stack->content)
			stack->pos++;
		stack = stack->next;
	}
}
