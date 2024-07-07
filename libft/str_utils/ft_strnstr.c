/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 08:36:42 by aagdemir          #+#    #+#             */
/*   Updated: 2024/06/23 20:41:43 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		needlen;
	size_t	i;

	i = 0;
	needlen = ft_strlen(needle);
	if (needlen == 0)
		return ((char *)(haystack));
	while (haystack[i] != '\0' && i + needlen <= len)
	{
		if (ft_strncmp(haystack + i, needle, needlen) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;
// 	char	*s3;
// 	char	*s4;

// 	s1 = "MZIRIBMZIRIBMZE123";
// 	s2 = "MZIRIBMZE";
// 	s3 = "MZIRIBMZIRIBMZE123";
// 	s4 = "MZIRIBMZE";
// 	size_t max = ft_strlen(s2);
// 	printf("homemade func:		%s\n", ft_strnstr(s1, s2, max));
// 	printf("supermarket func:	%s\n", strnstr(s3, s4, max));
// 	return (0);
// }
