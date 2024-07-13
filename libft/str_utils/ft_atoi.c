/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 08:43:12 by aagdemir          #+#    #+#             */
/*   Updated: 2024/06/23 20:40:48 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	idx;
	int	sign;
	int	nomoresign;

	sign = 1;
	idx = 0;
	nomoresign = 0;
	while ((str[idx] > 8 && str[idx] < 14) || str[idx] == 32)
		idx++;
	while (str[idx] == '+' || str[idx] == '-')
	{
		if (nomoresign == 1)
			return (0);
		if (str[idx] == '-')
			sign = -sign;
		idx++;
		nomoresign = 1;
	}
	result = 0;
	while (str[idx] >= '0' && str[idx] <= '9')
		result = result * 10 + (str[idx++] - '0');
	return (sign * result);
}

// #include <stdio.h>
// int main()
// {

// 	char *testStr1 = " ---+---+1234ab567";
// 	char *testStr2 = "  ++456xyz";
// 	char *testStr3 = "  -789!@#$^";
// 	char *testStr4 = "   +531--456*789";
// 	char *testStr5 = "   -67 34 56";
// 	char *testStr6 = " ---+--+9876ab567";

// 	printf("testStr1: %d\n", ft_atoi(testStr1));
// 	printf("testStr2: %d\n", ft_atoi(testStr2));
// 	printf("testStr3: %d\n", ft_atoi(testStr3));
// 	printf("testStr4: %d\n", ft_atoi(testStr4));
// 	printf("testStr5: %d\n", ft_atoi(testStr5));
// 	printf("testStr6: %d\n", ft_atoi(testStr6));
// 	return (0);
// }