/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_2_3_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:48:38 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/15 12:45:39 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	algo_2(t_stack **stack, t_push *push)
{
	t_stack	*tmp;

	tmp = *stack;
	if (tmp->content > tmp->next->content)
		s_swap(stack, 'a', push);
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
		if (tmp == NULL)
			return ;
		num1 = tmp->content;
		tmp = tmp->next;
		num2 = tmp->content;
		tmp = tmp->next;
		num3 = tmp->content;
		if ((num1 > num2 && num1 < num3 && num2 < num3)
			|| (num1 > num3 && num2 > num3 && num1 > num2)
			|| (num1 < num2 && num1 < num3 && num2 > num3))
			s_swap(stack1, 'a', push);
		if (num1 > num2 && num1 > num3 && num2 < num3)
			r_swap(stack1, 'a', push);
		if (num1 < num2 && num1 > num3 && num2 > num3)
			r_rev_swap(stack1, 'a', push);
	}
	return ;
}





/* void	algo_5(t_list **stack_a, t_list **stack_b, t_push *push)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (data->count_b < 2)
	{
		tmp = *stack_a;
		max_min(*stack_a, data, 'a');
		if (tmp->content == data->max_a || tmp->content == data->min_a)
			ft_pb(stack_a, stack_b, data);
		else if (data->count_b == 1)
			ra_rra(stack_a, data, data->max_a);
		else
			ra_rra(stack_a, data, data->min_a);
	}
	select_al(stack_a, stack_b, data);
	while (data->count_b != 0)
	{
		ft_move_a(stack_a, stack_b, data);
	}
} */

