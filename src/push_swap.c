/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:37:26 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/15 13:25:57 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(t_stack **stack, char **av, t_push *push)
{
	put_arg_to_int(stack, av, push);
}

int	main(int ac, char *av[])
{
	t_push	*push;
/* 	t_push	*tmp; */

	push = NULL;
	if (ac < 2)
		exit_ps("need-arg");
	else
	{
		push = ft_init_push(push);
		push_swap(&(push->a), av, push);
		printf("\nNodo: %d   Pos: %d\n", push->a->content, push->a->pos);
		printf("\nNodo: %d   Pos: %d\n", push->a->next->content, push->a->next->pos);
		printf("\nNodo: %d   Pos: %d\n", push->a->next->next->content, push->a->next->next->pos);
/* 		printf("\nNodo: %d   Pos: %d\n", push->a->next->next->next->content, push->a->next->next->next->pos);
		printf("\nNodo: %d   Pos: %d\n\n\n", push->a->next->next->next->next->content, push->a->next->next->next->next->pos);
		 */algo_3(&push->a, push);
		printf("\nNodo: %d   Pos: %d\n", push->a->content, push->a->pos);
		printf("\nNodo: %d   Pos: %d\n", push->a->next->content, push->a->next->pos);
		printf("\nNodo: %d   Pos: %d\n", push->a->next->next->content, push->a->next->next->pos);
	/* 	printf("\nNodo: %d   Pos: %d\n", push->a->next->next->next->content, push->a->next->next->next->pos);
		printf("\nNodo: %d   Pos: %d\n", push->a->next->next->next->next->content, push->a->next->next->next->next->pos);
		 */printf("Movimientos: %d\n", push->moves);
		count_nums(push->a, push, 'a');
		printf("tamaño del stack A: %d\n", push->len_a);
	}
	return (0);
}
