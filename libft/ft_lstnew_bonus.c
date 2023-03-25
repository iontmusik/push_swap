/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:56:12 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/05 22:02:55 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>

t_list	*ft_lstnew(void *content)
{	
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

/*int	main(void)
{
	char	*valor;
	t_list	*list;

	valor = "hola que tal";
	list = ft_lstnew(valor);
	printf("%s\n", list->content);
	return (0);
}*/
