/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:07:27 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/20 12:11:02 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/push_swap.h"

int	checkparams(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] < '0' || argv[i] > '9') && argv[i] != '-')
			return (1);
		if (argv[i + 1] == '-')
			return (1);
		i++;
	}
	return (0);
}

void	argcheck(char **argv, t_stack **stack_a)
{
	char	**av;
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) == 0 || (ft_strlen(argv[i]) == 1
				&& (argv[i][0] == ' ' || argv[i][0] == '-')))
			ft_error();
		av = ft_split(argv[i], ' ');
		j = 0;
		while (av[j])
		{
			if (checkparams(av[j]) != 0)
				ft_error();
			put_arg_to_int(stack_a, ft_atoi(av[j]));
			j++;
		}
		ft_freestr(av);
		i++;
	}
	ft_lstorder(stack_a);
	return ;
}

void	duplicate_nums(t_stack *stack, int num)
{
	while (stack->next != NULL)
	{
		if (stack->content == num)
			ft_error();
		stack = stack->next;
	}
	return ;
}

