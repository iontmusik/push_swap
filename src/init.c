/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:50:00 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/03 17:41:19 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


t_stack	*ft_lstnew_ps(int content)
{	
	t_stack	*list;

	list = (t_stack *)malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

t_push *ft_init_push(t_push *push)
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

void position_nums(char **av, t_push *push)
{
    int i;
    char *str;
    int j;

    i = 1;
    j = 0;
	if (!push)
		return ;
	str = malloc(sizeof(char));
    while (av[i])
    {
		str = ft_strjoin(str, av[i]);
        i++;
    }
	printf("%s\n", str);
	//push->split = ft_split(str, ' ');
/* 	printf("%s\n", push->split[0]);
	printf("%s\n", push->split[1]);
	printf("%s\n", push->split[2]);
	printf("%s\n", push->split[3]); */
	
}