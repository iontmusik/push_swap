/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:13:19 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/23 18:31:49 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra_rra(t_stack **stack_a, t_push *push, int pos)
{
	if (pos < (push->len_a / 2))
		ra_swap(stack_a, push);
	else
		r_reva_swap(stack_a, push);
}

void	r_reva_swap(t_stack **stack_a, t_push *push)
{
	t_stack	*last;
	t_stack	*tmp;

	last = *stack_a;
	tmp = *stack_a;
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *stack_a;
	*stack_a = last;
	tmp->next = NULL;
	ft_putstr_fd("rra\n", 1);
	push->moves++;
	return ;
}

void	r_revb_swap(t_stack **stack_b, t_push *push)
{
	t_stack	*last;
	t_stack	*tmp;

	last = *stack_b;
	tmp = *stack_b;
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *stack_b;
	*stack_b = last;
	tmp->next = NULL;
	ft_putstr_fd("rrb\n", 1);
	push->moves++;
	return ;
}

void	auxrrb(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*tmp;

	last = *stack_b;
	tmp = *stack_b;
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *stack_b;
	*stack_b = last;
	tmp->next = NULL;
}

void	rr_rev_swap(t_stack **stack1, t_stack **stack2, t_push *push)
{
	t_stack	*last;
	t_stack	*tmp;

	last = *stack1;
	tmp = *stack1;
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *stack1;
	*stack1 = last;
	tmp->next = NULL;
	auxrrb(stack2);
	ft_putstr_fd("rrr\n", 1);
	push->moves++;
	return ;
}
