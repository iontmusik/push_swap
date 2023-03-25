/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:24:07 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/05 18:54:42 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int				i;
	unsigned int	j;

	i = 0;
	while (src[i])
		i++;
	j = 0;
	if (dstsize > 0)
	{
		while (src[j] && j < (unsigned int) dstsize -1)
		{
			dst[j] = (char) src[j];
			j++;
		}
		dst[j] = '\0';
	}
	return (i);
}

/*int	main(void)
{
	char	dst[] = "hola que tal";
	char	src[] = "emperador";
	int		dstsize;

	dstsize = 7;
	printf("%lu\n", ft_strlcpy(dst, src, dstsize));
	printf("%lu", strlcpy(dst, src, dstsize));
	return (0);
}*/
