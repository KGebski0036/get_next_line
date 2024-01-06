/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:22:29 by kgebski           #+#    #+#             */
/*   Updated: 2023/05/27 18:52:29 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str != 0)
		while (str[i])
			i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (s[0] == 0 || ft_strlen(s) <= start)
		return (empty_str());
	sub = 0;
	if (len > ft_strlen(s))
		sub = malloc(ft_strlen(s) + 1);
	else
		sub = malloc(len + 1);
	if (!sub)
		return (0);
	while (i < len && s[start])
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = 0;
	return (sub);
}

char	*empty_str(void)
{
	char	*empty;

	empty = (char *)malloc(1);
	if (!empty)
		return (NULL);
	empty[0] = '\0';
	return (empty);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ldst;
	size_t	lsrc;
	size_t	i;
	size_t	j;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	i = 0;
	j = ldst;
	if (ldst < dstsize - 1 && dstsize > 0)
	{
		while (src[i] && (ldst + i < dstsize - 1))
		{
			dst[j++] = src[i++];
		}
		dst[j] = 0;
	}
	if (ldst >= dstsize)
		ldst = dstsize;
	return (ldst + lsrc);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	size_s1;
	size_t	size_s2;
	size_t	i;

	if (s1 == 0)
		s1 = empty_str();
	if (s1 == 0)
		return (0);
	i = 0;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	new = malloc(size_s1 + size_s2 + 1);
	if (!new)
		return (0);
	while (i < size_s1 + 1)
	{
		((char *)new)[i] = ((char *)s1)[i];
		i++;
	}
	ft_strlcat(new, s2, size_s1 + size_s2 + 1);
	free(s1);
	return (new);
}
