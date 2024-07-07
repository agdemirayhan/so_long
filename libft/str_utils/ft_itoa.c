/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:08:01 by aagdemir          #+#    #+#             */
/*   Updated: 2024/06/23 20:41:16 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	digitcounter(int n)
{
	int	temp;
	int	digit;

	digit = 0;
	temp = n;
	if (n == -2147483648)
		return (11);
	while (temp != 0)
	{
		digit++;
		temp /= 10;
	}
	if (n == 0)
		digit = 1;
	if (n < 0)
		digit++;
	return (digit);
}

char	*reverser(char *str, int i)
{
	int	temp;
	int	start;
	int	end;

	if (str[0] == '-')
		start = 1;
	else
		start = 0;
	end = i - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (str);
}

char	*minhandler(void)
{
	char	*str;

	str = (char *)malloc(12 * sizeof(char));
	if (!str)
		return (NULL);
	str = ft_memcpy(str, "-2147483648", 11);
	str[11] = '\0';
	return (str);
}

char	*stringhandler(char *str, int n)
{
	int	i;
	int	digit;

	i = 0;
	if (n == 0)
		str[i++] = '0';
	else if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	while (n != 0)
	{
		digit = n % 10;
		str[i++] = '0' + digit;
		n /= 10;
	}
	str[i] = '\0';
	reverser(str, i);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == -2147483648)
		return (minhandler());
	str = (char *)malloc((digitcounter(n) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	stringhandler(str, n);
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int x = -42;
// 	int length = snprintf(NULL, 0, "%d", x);
// 	char *str = malloc(length + 1);
// 	snprintf(str, length + 1, "%d", x);
// 	printf("%s\n", str);
// 	free(str);
// }