/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:51:42 by aagdemir          #+#    #+#             */
/*   Updated: 2024/06/23 20:41:26 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*str;
	size_t	totallen;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	totallen = s1len + s2len;
	str = (char *)malloc((totallen + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, s1len);
	ft_memcpy(str + s1len, s2, s2len);
	str[totallen] = '\0';
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {

// 	printf("%s\n",ft_strjoin("whatever ", "lorem ipsum dolor sit amet"));
// }
