/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:06:58 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/20 18:33:00 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* static int	get_max_bits(t_push *push)
{
	t_stack	*tmp;
	int		max;
	int		max_bits;

	tmp = *stack;
	max = tmp->pos;
	max_bits = 0;
	max = push->posmax_a;
	while (tmp)
	{
		if (tmp->pos > max)
			max = tmp->pos;
		tmp = tmp->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
 */
static int	get_max_bits(t_stack *stack)
{
	t_stack	*tmp;
	int		max;
	int		max_bits;

	tmp = stack;
	max = tmp->pos;
	max_bits = 0;
/* 	max = push->posmax_a; */
	while (tmp)
	{
		if (tmp->pos > max)
			max = tmp->pos;
		tmp = tmp->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, t_push *push)
{
	t_stack	*tmp;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	tmp = *stack_a;
	size = ft_lstsize_ps(*stack_a);
	max_bits = get_max_bits(*stack_a);
	tiny_sort(t_stack)
	{
		int	highest;
		
		highest =
	}
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			tmp = *stack_a;
			if (((tmp->pos >> i) & 1) = 1)
				ra_swap(stack_a, push);
			else
				pb_swap(stack_a, stack_b, push);
		}
		while (ft_lstsize_ps(*stack_b) != 0)
			pa_swap(stack_a, stack_b, push);
		i++;
	}
}
