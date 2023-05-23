/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_2_3_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:48:38 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/20 16:57:18 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	select_algo(t_stack **stack_a, t_stack **stack_b, t_push *push)
{
	push->len_a = ft_lstsize_ps(*stack_a);
	push->len_b = ft_lstsize_ps(*stack_b);
	maxminstack(*stack_a, push, 'a');
	posmaxmin(*stack_a, push, 'a');
	if (push->len_a <= 2)
		algo_2(stack_a, push);
	else if (push->len_a <= 3)
		algo_3(stack_a, push);
	else if (push->len_a <= 5)
		algo_5(stack_a, stack_b, push);
	else if (push->len_a > 5)
		radix_sort(stack_a, stack_b, push);
	//free(stack_b);
}


void	algo_2(t_stack **stack, t_push *push)
{
	t_stack	*tmp;

	tmp = *stack;
	if (tmp->content > tmp->next->content)
		sa_swap(stack, push);
}

void	algo_3(t_stack **stack1, t_push *push)
{
	int			num1;
	int			num2;
	int			num3;
	t_stack		*tmp;

	num1 = 0;
	num2 = 0;
	num3 = 0;
	while (!(num1 < num2 && num2 < num3 && num1 < num3))
	{
		tmp = (*stack1);
		num1 = tmp->content;
		tmp = tmp->next;
		num2 = tmp->content;
		tmp = tmp->next;
		num3 = tmp->content;
		if ((num1 > num2 && num1 < num3 && num2 < num3) 
			|| (num1 > num3 && num2 > num3 && num1 > num2)
			|| (num1 < num2 && num1 < num3 && num2 > num3))
			sa_swap(stack1, push);
		if (num1 > num2 && num1 > num3 && num2 < num3)
			ra_swap(stack1, push);
		if (num1 < num2 && num1 > num3 && num2 > num3)
			r_reva_swap(stack1, push);
	}
}

void	algo_5(t_stack **stack_a, t_stack **stack_b, t_push *push)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (push->len_b < 2)
	{
		tmp = *stack_a;
		posmaxmin(*stack_a, push, 'a');
		if (tmp->content == push->max_a || tmp->content == push->min_a)
			pb_swap(stack_a, stack_b, push);
		else if (push->len_b == 1)
			ra_rra(stack_a, push, push->max_a);
		else
			ra_rra(stack_a, push, push->min_a);
	}
	select_algo(stack_a, stack_b, push);
	while (push->len_b != 0)
	{
		ft_move_a(stack_a, stack_b, push);
	}
}

void	ft_move_a(t_stack **stack_a, t_stack **stack_b, t_push *push)
{
	int		a;
	t_stack	*tmp;

	tmp = *stack_a;
	a = tmp->content;
	tmp = *stack_b;
	pa_swap(stack_a, stack_b, push);
	if (tmp->content > a)
		ra_swap(stack_a, push);
	return ;
}

