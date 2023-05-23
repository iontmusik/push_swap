/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:29:07 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/23 18:31:17 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa_swap(t_stack **stack_a, t_push *push)
{
	t_stack	*swap;
	t_stack	*swap2;

	swap = *stack_a;
	swap2 = swap->next;
	*stack_a = swap2;
	swap->next = swap2->next;
	swap2->next = swap;
	ft_putstr_fd("sa\n", 1);
	push->moves++;
	return ;
}

void	sb_swap(t_stack **stack_b, t_push *push)
{
	t_stack	*swap;
	t_stack	*swap2;

	swap = *stack_b;
	swap2 = swap->next;
	*stack_b = swap2;
	swap->next = swap2->next;
	swap2->next = swap;
	ft_putstr_fd("sb\n", 1);
	push->moves++;
	return ;
}

void	ss_swap(t_stack **stack_a, t_stack **stack_b, t_push *push)
{
	t_stack	*swap;
	t_stack	*swap2;

	swap = *stack_a;
	swap2 = swap->next;
	*stack_a = swap2;
	swap->next = swap2->next;
	swap2->next = swap;
	swap = NULL;
	swap2 = NULL;
	swap = *stack_b;
	swap2 = swap->next;
	*stack_b = swap2;
	swap->next = swap2->next;
	swap2->next = swap;
	ft_putstr_fd("ss\n", 1);
	push->moves++;
	return ;
}

void	pa_swap(t_stack **stacka, t_stack **stackb, t_push *push)
{
	t_stack	*tmp;

	if (*stackb == NULL)
		return ;
	tmp = *stackb;
	*stackb = (*stackb)->next;
	tmp->next = *stacka;
	*stacka = tmp;
	ft_putstr_fd("pa\n", 1);
	push->len_a++;
	push->len_b--;
	push->moves++;
	return ;
}

void	pb_swap(t_stack **stacka, t_stack **stackb, t_push *push)
{
	t_stack	*tmp;

	if (stacka == NULL)
		return ;
	tmp = *stacka;
	*stacka = (*stacka)->next;
	tmp->next = *stackb;
	*stackb = tmp;
	ft_putstr_fd("pb\n", 1);
	push->len_a--;
	push->len_b++;
	push->moves++;
	return ;
}
