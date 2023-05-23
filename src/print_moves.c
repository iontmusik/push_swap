/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:09:14 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/18 14:05:35 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_and_moves_s(t_push *push, char c)
{
	if (c == 'a')
		printf("sa\n");
	else if (c == 'b')
		printf("sb\n");
	push->moves++;
}

void	print_and_moves_p(t_push *push, char c)
{
	if (c == 'b')
	{
		push->len_a -= 1;
		push->len_b += 1;
		printf("pb\n");
		return ;
	}
	else if (c == 'a')
	{
		push->len_a += 1;
		push->len_b -= 1;
		printf("pa\n");
	}
	push->moves++;
}

void	print_and_moves_r(t_push *push, char c)
{
	if (c == 'a')
		printf("ra\n");
	else if (c == 'b')
		printf("rb\n");
	push->moves++;
}

void	print_and_moves_w(t_push *push, char c)
{
	if (c == 'a')
		printf("rra\n");
	else if (c == 'b')
		printf("rrb\n");
	push->moves++;
}
