/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:50:00 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/03 13:07:39 by jtorre-s         ###   ########.fr       */
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

void	ft_construction_lst(t_stack **lst, t_stack *new)
{
	if (lst == NULL)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
        while ((*lst)->next)
        {
		    (*lst) = (*lst)->next;
	    }
         if (new)
            new->next = new; 
	}
    return ;
}

void put_arg_to_int(t_stack *stack, char **av, t_push *push)
{
    int i;
    int num;
    t_stack *new;

    i = 1;
	if (push)
    {
        while (av[i] != NULL)
    	{
            num = atoi_ps(av[i]);
            new = ft_lstnew_ps(num);
            ft_lstadd_back_ps(&stack, new);
            printf("%d", stack->content);
            stack = stack->next;
            printf("adios\n");
            i++;
        }
    }
}
