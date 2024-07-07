/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:08:08 by aagdemir          #+#    #+#             */
/*   Updated: 2024/06/23 20:42:26 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			return ((int)(str1[i] - str2[i]));
		}
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int  main(void)
// {
//  char str2[25] = "This is the way";
//  char str1[25] = "This iz the way";
//  int nb = 15;

//  printf("%d\n", ft_memcmp(str1, str2, nb));
//  printf("%d\n", memcmp(str1, str2, nb));
//  // printf("%d\n", strncmp(str1, str2,nb));

//  return (0);
// }