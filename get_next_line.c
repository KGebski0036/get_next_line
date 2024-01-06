/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:59:32 by kgebski           #+#    #+#             */
/*   Updated: 2023/05/27 18:50:12 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saved_str;
	char		*result;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	saved_str = update_saved_str(saved_str, fd);
	if (!saved_str)
		return (0);
	result = get_result(saved_str);
	saved_str = get_rest_of_str(saved_str);
	return (result);
}

char	*update_saved_str(char	*saved_str, int fd)
{
	char	*buffer;
	int		rsize;

	rsize = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (!ft_strchr(saved_str, '\n') && rsize != 0)
	{
		rsize = read(fd, buffer, BUFFER_SIZE);
		if (rsize == -1)
		{
			free(buffer);
			free(saved_str);
			return (0);
		}
		buffer[rsize] = '\0';
		saved_str = ft_strjoin(saved_str, buffer);
	}
	free(buffer);
	return (saved_str);
}

char	*get_result(char *saved_str)
{
	int	i;

	i = 0;
	if (!saved_str[0])
		return (0);
	while (saved_str[i] && saved_str[i] != '\n')
		i++;
	i++;
	return (ft_substr(saved_str, 0, i));
}

char	*get_rest_of_str(char	*saved_str)
{
	char	*result;
	int		i;

	i = 0;
	while (saved_str[i] && saved_str[i] != '\n')
		i++;
	i++;
	result = ft_substr(saved_str, i, ft_strlen(saved_str));
	if (result[0] == '\0')
	{
		free(result);
		result = 0;
	}
	free(saved_str);
	return (result);
}

char	*ft_strchr(char *s, int c)
{
	char	cc;

	if (!s)
		return (0);
	cc = (char)c;
	while (*s != cc && *s)
	{
		s++;
	}
	if (*s == cc)
		return ((char *)(s));
	return (0);
}
