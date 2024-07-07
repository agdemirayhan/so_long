/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 10:24:10 by aagdemir          #+#    #+#             */
/*   Updated: 2024/06/23 20:42:24 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		k;
	size_t				i;
	const unsigned char	*str;

	k = (unsigned char)c;
	str = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == k)
		{
			return ((void *)(str + i));
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*src;
// 	int		size;
// 	char	*s2;

// 	src = "/|\x12\xff\x09\x42\2002\42|\\";
// 	size = 10;
// 	s2 = ft_memchr(src, '\200', size);
// 	// printf("%s\n", memchr(s1, '@', strlen(s1)));
// 	printf("%s\n", s2);
// 	return (0);
// }

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char *s1 = "ayhanagdemir@microsoft.com";

// 	char *s2 = ft_memchr(s1, '@', ft_strlen(s1));

// 	// printf("%s\n", memchr(s1, '@', strlen(s1)));
// 	printf("%s\n", s2);

// 	return (0);
// }