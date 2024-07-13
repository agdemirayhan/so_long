/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 10:21:49 by aagdemir          #+#    #+#             */
/*   Updated: 2024/06/23 20:41:28 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	destlen;
	size_t	srclen;
	size_t	i;
	size_t	j;

	i = 0;
	srclen = ft_strlen(src);
	j = ft_strlen(dst);
	destlen = j;
	if (!dst && dstsize == 0)
		return (srclen);
	else if (dstsize <= destlen)
		return (dstsize + srclen);
	while (src[i] != '\0' && j < dstsize - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (destlen + srclen);
}

// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>

// int	main(void)
// {

// 	char dest[40] = "absaasdasd";
// 	// char src[10] = "bcdef";
// 	printf("%zu\n",strlcat(dest, "lorem ipsum dolor sit amet", 2));
// 	write(1, "\n", 1);
// 	write(1, dest, 20);
// }
