/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:17:53 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/06 14:14:20 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>
#include "libft.h"
#include<stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst1;
	char	*src1;
	int		i;

	i = 0;
	if (len == 0)
		return (dst);
	if (dst <= src)
	{
		ft_memcpy(dst, src, len);
		return (dst);
	}
	dst1 = (char *)dst + len - 1;
	src1 = (char *)src + len - 1;
	while (len)
	{
		dst1[i] = src1[i];
		i--;
		len--;
	}
	return (dst);
}

/*int	main(void)
{
	char	str[] = "lorem ipsum dolor sit amet";
	char	dst[] = "consectetur";
	char	str1[] = "lorem ipsum dolor sit amet";
	char	dst1[] = "consectetur";

	printf("%s\n", memmove(dst, str, 5));
	printf("%s\n", ft_memmove(dst1, str1, 5));
}*/

/*int		main(int argc, const char *argv[])
{
	char	src[] = "lorem ipsum dolor sit amet";
	char	*dest;
	int		arg;

	dest = src + 1;
	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		if (dest != ft_memmove(dest, "consectetur", 5))
			write(1, "dest's adress was not returned\n", 31);
		write(1, dest, 22);
	}
	else if (arg == 2)
	{
		if (dest != ft_memmove(dest, "con\0sec\0\0te\0tur", 10))
			write(1, "dest's adress was not returned\n", 31);
		write(1, dest, 22);
	}
	else if (arg == 3)
	{
		if (dest != ft_memmove(dest, src, 8))
			write(1, "dest's adress was not returned\n", 31);
		write(1, dest, 22);
	}
	else if (arg == 4)
	{
		if (src != ft_memmove(src, dest, 8))
			write(1, "dest's adress was not returned\n", 31);
		write(1, dest, 22);
	}
	else if (arg == 5)
	{
		if (src != ft_memmove(src, dest, 0))
			write(1, "dest's adress was not returned\n", 31);
		write(1, dest, 22);
	}
	return (0);
}*/