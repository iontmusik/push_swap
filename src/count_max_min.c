/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_max_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:29:29 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/23 18:08:57 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_minimo(t_stack *stack, t_push *push, char c)
{
	push->min_a = 2147483647;
	push->min_b = 2147483647;
	if (c == 'a')
	{
		while (stack != NULL)
		{
			if (stack->content < push->min_a)
				push->min_a = stack->content;
			stack = stack->next;
		}
	}
	if (c == 'b')
	{
		while (stack != NULL)
		{
			if (stack->content < push->min_b)
				push->min_b = stack->content;
			stack = stack->next;
		}
	}
}

void	ft_maximo(t_stack *stack, t_push *push, char c)
{
	push->max_a = -2147483648;
	push->max_b = -2147483648;
	if (c == 'a')
	{
		while (stack != NULL)
		{
			if (stack->content > push->max_a)
				push->max_a = stack->content;
			stack = stack->next;
		}
	}
	if (c == 'b')
	{
		while (stack != NULL)
		{
			if (stack->content > push->max_b)
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

int	count_nums(t_stack *stack)
{	
	int	i;

	i = 0;
	if (stack == NULL)
		return (0);
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	position_nums(t_stack *stack, t_stack *new)
{
	new->pos = 0;
	while (stack)
	{
		if (new->content > stack->content)
			new->pos++;
		else if (new->content < stack->content)
			stack->pos++;
		stack = stack->next;
	}
}
