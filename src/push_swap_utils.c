/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:30:11 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/03 14:59:08 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack *ft_lstlast_ps(t_stack *lst)
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
    return ;
}

void	ft_lstiter_ps(t_stack *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
}

void put_arg_to_int(t_stack **stack, char **av, t_push *push)
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
            ft_lstadd_back_ps(&(*stack), new);
            //printf("%d", (*stack)->content);
            stack = &(*stack)->next;
            //printf("adios\n");
            i++;
        }
    }
}
