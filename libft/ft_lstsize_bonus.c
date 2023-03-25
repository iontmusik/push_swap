/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:16:13 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/02 18:28:59 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	char	valor;
	t_list	*lst;

	printf("%d", ft_lstsize(lst));
	return (0);
}
*/