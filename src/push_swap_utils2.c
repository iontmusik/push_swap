/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:42:20 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/23 18:32:28 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_lstsize_ps(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst -> next;
	}
	return (i);
}

void	stackclear(t_stack **stack_a)
{
	t_stack	*cpy;

	if (!stack_a)
		return ;
	cpy = *stack_a;
	while (cpy)
	{
		cpy = (*stack_a)->next;
		free(*stack_a);
		*stack_a = cpy;
	}
	stack_a = NULL;
	return ;
}

void	ft_lstorder(t_stack **stack_a)
{
	t_stack	*cpy;
	t_stack	*cpy2;

	cpy = *stack_a;
	cpy2 = cpy->next;
	while (cpy->next != NULL)
	{
		if (cpy->content > cpy2->content)
			return ;
		cpy = cpy->next;
		cpy2 = cpy2->next;
	}
	exit (0);
}
