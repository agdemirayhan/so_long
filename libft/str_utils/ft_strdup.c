/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:14:26 by aagdemir          #+#    #+#             */
/*   Updated: 2024/06/23 20:41:22 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		s1len;

	s1len = ft_strlen(s1);
	s2 = (char *)malloc((s1len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	ft_memcpy(s2, s1, s1len);
	s2[s1len] = '\0';
	return (s2);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s\n", ft_strdup("test1"));

// 	return (0);
// }