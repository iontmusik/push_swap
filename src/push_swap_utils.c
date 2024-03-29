/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:30:11 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/23 18:28:19 by jtorre-s         ###   ########.fr       */
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

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack	*cpy;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		cpy = ft_lstlast_ps(*lst);
		cpy -> next = new;
	}
	return ;
}

void	ft_lstiter_ps(t_stack *lst)
{
	while (lst && lst->next != NULL)
	{
		lst = lst->next;
	}
}

void	put_arg_to_int(t_stack **stack, int num)
{
	t_stack	*tmp;

	tmp = NULL;
	tmp = ft_lstnew_ps(num);
	ft_lstadd_back_ps(stack, tmp);
	duplicate_nums(*stack, num);
	position_nums(*stack, tmp);
	tmp = NULL;
}
