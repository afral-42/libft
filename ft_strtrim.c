/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:59:47 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/06 12:28:20 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int is_in_set(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	get_trimmed_size(char const *s1, char const *set, size_t *index)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s1[i] != '\0' && is_in_set(set, s1[i]))
		i++;
	*index = i;
	while (s1[i] != '\0' && !is_in_set(set, s1[i]))
	{
		i++;
		len++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	size_t	index;
	char	*result;

	len = get_trimmed_size(s1, set, &index);
	if (!len)
		return (ft_strdup(""));
	result = malloc((len + 1) * sizeof(char));
	i = 0;
	while (i < len)
	{
		result[i] = s1[index + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
