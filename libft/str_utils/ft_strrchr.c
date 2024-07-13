/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 10:23:35 by aagdemir          #+#    #+#             */
/*   Updated: 2024/06/23 20:41:46 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	a;
	int		i;

	a = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == a)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int  main(void)
// {
//  char *s1 = "this is a test text";
//  char c = 'x';
//  // printf("%s\n", ft_strchr(s1, c));
//  printf("%s\n", strchr(s1, c));

// }
