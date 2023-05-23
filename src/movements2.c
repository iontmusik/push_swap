/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:40:19 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/20 13:33:30 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra_swap(t_stack **stack, t_push *push)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	ft_putstr_fd("ra\n", 1);
	push->moves++;
	return ;
}

void	rb_swap(t_stack **stack, t_push *push)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	ft_putstr_fd("rb\n", 1);
	push->moves++;
	return ;
}

void	rr_swap(t_stack **stack1, t_stack **stack2, t_push *push)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack1 || !stack2)
		return ;
	first = *stack1;
	last = *stack1;
	while (last->next)
		last = last->next;
	*stack1 = first->next;
	first->next = NULL;
	last->next = first;
	first = NULL;
	last = NULL;
	first = *stack2;
	last = *stack2;
	while (last->next)
		last = last->next;
	*stack2 = first->next;
	first->next = NULL;
	last->next = first;
	ft_putstr_fd("rr\n", 1);
	push->moves++;
	return ;
}

