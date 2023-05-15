/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:30:11 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/15 11:05:56 by jtorre-s         ###   ########.fr       */
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

void	put_arg_to_int(t_stack **stack, char **av, t_push *push)
{
	int		i;
	int		num;
	int		j;
	char	**temp;
	t_stack	*new;

	i = 0;
	if (push)
	{
		while (av[++i] != NULL)
		{
			j = -1;
			temp = ft_split(av[i], ' ');
			while (temp[++j])
			{
				num = atoi_ps(temp[j]);
				new = ft_lstnew_ps(num);
				ft_lstadd_back_ps(stack, new);
				position_nums((*stack), new);
			}
			free(temp);
		}
	}
}

void	position_nums(t_stack *stack, t_stack *new)
{
	while (stack)
	{
/* 	 	printf("%p - %p\n", &tmp, stack);  */
		if (new->content > stack->content)
			new->pos++;
		else if (new->content < stack->content)
			stack->pos++;
		stack = stack->next;
	}
}
