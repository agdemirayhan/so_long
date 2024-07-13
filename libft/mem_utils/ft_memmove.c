/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:02:53 by aagdemir          #+#    #+#             */
/*   Updated: 2024/06/23 20:42:30 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*destination;
	char	*source;

	destination = (char *)dst;
	source = (char *)src;
	if (dst == src)
		return (dst);
	if (source < destination)
	{
		while (len--)
			*(destination + len) = *(source + len);
		return (dst);
	}
	while (len--)
		*destination++ = *source++;
	return (dst);
}
