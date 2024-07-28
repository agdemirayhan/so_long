/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:42:37 by klamprak          #+#    #+#             */
/*   Updated: 2024/07/28 13:05:45 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"
#include "get_next_line.h"
#include <stdlib.h>

static char	*get_result(char **mem_str, int *k);
static char	*update_mem_str(char **mem_str, int i, char **result);

// return NULL if mem_str == NUL or mem_str not contain any new line
// return the first new line of mem_str and updates mem_str with the rest of it
char	*get_first_line(char **mem_str)
{
	int		i;
	char	*result;

	result = get_result(mem_str, &i);
	if (!result)
		return (NULL);
	if ((*mem_str)[i + 1] == '\0')
	{
		free(*mem_str);
		*mem_str = NULL;
		return (result);
	}
	return (update_mem_str(mem_str, i, &result));
}

static char	*update_mem_str(char **mem_str, int i, char **result)
{
	char	*temp_mem_str;
	int		j;

	temp_mem_str = malloc((ft_strlen2(*mem_str) - i) * sizeof(char));
	if (!temp_mem_str)
	{
		free(*result);
		return (NULL);
	}
	j = 0;
	while ((*mem_str)[++i] != '\0')
		temp_mem_str[j++] = (*mem_str)[i];
	temp_mem_str[j] = '\0';
	free(*mem_str);
	*mem_str = temp_mem_str;
	return (*result);
}

static char	*get_result(char **mem_str, int *k)
{
	char	*result;
	int		i;
	int		j;

	if (!(*mem_str))
		return (NULL);
	i = 0;
	while ((*mem_str)[i] != '\0' && (*mem_str)[i] != '\n')
		i++;
	if ((*mem_str)[i] == '\0' || i == 0)
		return (NULL);
	result = malloc((i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	j = -1;
	while (++j < i)
		result[j] = (*mem_str)[j];
	result[j] = '\0';
	*k = i;
	return (result);
}

int	ft_strlen2(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
