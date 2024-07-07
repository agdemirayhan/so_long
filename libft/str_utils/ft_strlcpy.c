/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 10:22:12 by aagdemir          #+#    #+#             */
/*   Updated: 2024/06/23 20:41:31 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char s1[10] = "test1test1";
// 	char *s2 = "kitap1";
// 	char s3[10] = "test1test1";
// 	char *s4 = "kitap1";

// 	ft_strlcpy(s1, s2, sizeof(char) * 3);
// 	printf("homemade:	%s\n", s1);

// 	strlcpy(s3, s4, sizeof(char) * 3);
// 	printf("supermarket:	%s\n", s1);

// 	return (0);
// }