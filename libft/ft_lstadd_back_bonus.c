/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:30:16 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/05 23:08:13 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ultimo;

	if (lst == NULL)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		ultimo = ft_lstlast(*lst);
		if (ultimo)
			ultimo->next = new;
	}
}

/*int	main(void)
{
	t_list	*lst;
	t_list	*j;
	t_list	*p;
	char	str[]  = "hola que tal estas";
	int		a;

	a = 2;
	lst->content = str;
	lst->next = j;
	j->content = &a;
	j->next = p;
	p->next = NULL;
	printf("%c", ft_lstadd_back(&lst, new);
	return (0);
}
*/