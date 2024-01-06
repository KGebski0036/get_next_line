/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:50:56 by kgebski           #+#    #+#             */
/*   Updated: 2023/05/27 18:02:56 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 123
# endif
# include <unistd.h>
# include <stdlib.h>

char			*get_next_line(int fd);
char			*update_saved_str(char	*saved_str, int fd);
char			*get_result(char	*saved_str);
char			*get_rest_of_str(char	*saved_str);
char			*ft_strchr(char *s, int c);
size_t			ft_strlen(const char *str);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*empty_str(void);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strjoin(char *s1, char *s2);

#endif