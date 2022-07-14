/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:28:15 by shogura           #+#    #+#             */
/*   Updated: 2022/04/20 17:54:20 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	size_t			malloc_size;
	void			*mem;
	unsigned char	*str;

	i = 0;
	str = NULL;
	malloc_size = count * size;
	if (malloc_size == 0)
		malloc_size = 1;
	mem = (void *)malloc(malloc_size);
	if (mem == NULL)
		return (NULL);
	str = (unsigned char *)mem;
	while (i < malloc_size)
		str[i++] = '\0';
	return (mem);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	charset;

	charset = (unsigned char)c;
	while (*s)
	{
		if (*s == charset)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_s;
	size_t	len;
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	new_s = malloc(sizeof(char) * (len + 1));
	if (new_s == NULL)
		return (NULL);
	while ((len + 1) > 0)
		new_s[len--] = '\0';
	while (*s1)
		new_s[i++] = *s1++;
	while (*s2)
		new_s[i++] = *s2++;
	return (new_s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*sub;

	i = 0;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		sub = (char *)malloc(sizeof(char) * 1);
	else
	{
		if (len > ft_strlen(s + start))
			len = ft_strlen(s + start);
		sub = (char *)malloc(sizeof(char) * (len + 1));
	}
	if (sub == NULL)
		return (NULL);
	while (i < len && s[start] && start < s_len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
