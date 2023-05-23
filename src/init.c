/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:50:00 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/23 15:17:34 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_init_push(t_push *push)
{
	push->split = NULL;
	push->moves = 0;
	push->len_a = 0;
	push->len_b = 0;
	push->max_a = 0;
	push->max_b = 0;
	push->min_a = 0;
	push->min_b = 0;
	push->posmax_a = 0;
	push->posmin_a = 0;
	push->posmax_b = 0;
	push->posmin_b = 0;
}
