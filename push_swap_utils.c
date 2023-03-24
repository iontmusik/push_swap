/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:30:11 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/03/24 15:59:57 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*t_stack	*ft_lstlast_ps(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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
}*/

void	ft_lstadd_front_ps(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}