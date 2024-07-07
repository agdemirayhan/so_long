/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 09:13:01 by aagdemir          #+#    #+#             */
/*   Updated: 2024/06/23 20:42:22 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*arr;

	arr = malloc(count * size);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, count * size);
	return (arr);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *str;

// 	str = ft_calloc(1000,sizeof(char));
// 	int i = 0;
// 	while(i < 1000)
// 	{
// 		printf("%c", str[i]);
// 		i++;
// 	}

// 	return (0);
// }