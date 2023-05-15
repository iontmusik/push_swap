/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:40:19 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/15 12:40:43 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rr_rev_swap(t_stack **stack1, t_stack **stack2, t_push *push)
{
	r_rev_swap(stack1, 'w', push);
	r_rev_swap(stack2, 'w', push);
	printf("rrr\n\n");
	push->moves++;
}