/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:37:26 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/23 18:15:31 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_push	*push;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	push = (t_push *)malloc(sizeof(t_push));
	if (push == NULL)
		exit(1);
	ft_init_push(push);
	if (!push)
		exit (1);
	if (ac < 2)
		ft_error();
	argcheck(av, &stack_a);
	select_algo(&stack_a, &stack_b, push);
	stackclear(&stack_a);
	free(push);
	return (0);
}
