/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:04:55 by aagdemir          #+#    #+#             */
/*   Updated: 2024/06/23 20:41:19 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (in_word)
				in_word = 0;
		}
		else
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		s++;
	}
	return (count);
}

static char	*duplicate_word(const char *s, char c)
{
	size_t	len;
	char	*dup;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, len + 1);
	return (dup);
}

int	ft_free(size_t i, char **result)
{
	while (i > 0)
	{
		free(result[i - 1]);
		i--;
	}
	free(result);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;

	result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			result[i] = duplicate_word(s, c);
			if (!result[i++])
			{
				ft_free(i, result);
				return (NULL);
			}
			while (*s && *s != c)
				s++;
		}
	}
	result[i] = NULL;
	return (result);
}

// int	main(void)
// {
// 	char	**result;

// 	// printf("%zu\n",count_words("this is a test text", 'x'));
// 	result = ft_split("this this hits this thist this this is a test text",
// 			' ');
// 	printf("ft_split: %s\n", *result); // Print the first word
// 	return (0);
// }
