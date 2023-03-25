/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:18:45 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/01 12:18:56 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	*ft_memset(void *s, int c, size_t len)
{
	size_t	a;
	char	*str;

	str = (char *)s;
	a = 0;
	while (a < len)
	{
		str[a] = (unsigned char)c;
		a++;
	}
	return (s);
}
