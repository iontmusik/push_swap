/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:37:26 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/20 18:26:26 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


int	main(int ac, char **av)
{
	t_push	*push;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*tmp;
	int 	i = 1;

	stack_a = NULL;
	stack_b = NULL;
	tmp = NULL;
	push = (t_push *)malloc(sizeof(t_push));
	if (push == NULL)
		exit(1);
	ft_init_push(push);
	if (!push)
		exit (1);
	if (ac < 2)
		ft_error();
	argcheck(av, &stack_a);
	tmp = stack_a;
	while (tmp)
	{
	//	printf("NODO %d  CONTENIDO %d Y POSICION: %d\n", i, tmp->content, tmp->pos);
		tmp = tmp->next;
		i++;
	}
	select_algo(&stack_a, &stack_b, push);
	tmp = stack_a;
	i = 1;
	while (tmp)
	{
/* 		printf("NODO %d  CONTENIDO %d Y POSICION: %d\n", i, tmp->content, tmp->pos);
		*/tmp = tmp->next;
		i++;
	}
	printf("%d MOVIMIENTOS", push->moves);
	stackclear(&stack_a);
	free(push);
	return (0);
}
