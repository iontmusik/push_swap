/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:30:11 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/03/29 14:03:58 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void ft_order_lst(t_stack *a, t_stack *new)
{
    while (a->next)
    {
        if (new->content > a->next->content)
        {
            a->next->position++;
        }
        else
        {
            a->position++;
        }
        a = a->next;
    }
} */

t_stack *ft_lstlast_ps(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)

		lst = lst->next;
	return (lst);

}

t_stack *ft_lstlast_ps2(t_stack *lst, t_stack *new, t_push *push)
{
	if (lst == NULL)
		return (NULL);
	push->cont_new = 1;
	while (lst->next)
	{
		if (new->content > lst->content)
		{
        	push->cont_new++;
			printf("suma new:\n");
		}
		else if (new->content < lst->content)
		{
            lst->position++;
			printf("suma lst: \n");
		}
		lst = lst->next;
	}
	//printf("%d\n", push->cont_new);
	return (lst);

}

void	ft_lstadd_back_ps2(t_stack **lst, t_stack *new, t_push *push)
{
	t_stack	*ultimo;

	if (lst == NULL)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		ultimo = ft_lstlast_ps2(*lst, new, push);
		
		new->position = push->cont_new;
		if (ultimo)
			ultimo->next = new;
	}
    return ;
}

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack	*ultimo;

	if (lst == NULL)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		ultimo = ft_lstlast_ps(*lst);
		if (ultimo)
			ultimo->next = new;
	}
    return ;
}

void	ft_lstiter_ps(t_stack *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
}
