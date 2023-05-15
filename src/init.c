/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:50:00 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/13 09:54:40 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_push	*ft_init_push(t_push *push)
{
	push = (t_push *)malloc(sizeof(t_push));
	if (push == NULL)
		exit(1);
	push->a = NULL;
	push->b = NULL;
	push->split = NULL;
	push->moves = 0;
	push->len = 0;
	push->len_a = 0;
	push->len_b = 0;
	push->cont_new = 0;
	return (push);
}
