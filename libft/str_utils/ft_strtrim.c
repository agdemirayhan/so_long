/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:15:07 by aagdemir          #+#    #+#             */
/*   Updated: 2024/06/23 20:41:48 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trimmed;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]) != NULL)
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]) != NULL)
		end--;
	len = end - start;
	trimmed = (char *)malloc((len + 1) * sizeof(char));
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, len + 1);
	return (trimmed);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *s1 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !";
//     char *s2 = "Hello \t  Please\n Trim me !";
//     char *ret = ft_strtrim(s1, " \n\t");

// 	printf("%s\n",ret);

// }