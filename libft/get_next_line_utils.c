/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:04:38 by aforcada          #+#    #+#             */
/*   Updated: 2026/03/13 20:08:19 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_strchr(char *str, char c);
char	*gnl_strlchr(char *str, char c, ssize_t len);
char	*gnl_strlcpy(char *str, ssize_t len);
char	*gnl_strlcat(char *s1, ssize_t len1, char *s2, ssize_t len2);

char	*gnl_strchr(char *str, char c)
{
	char	*s;

	if (!str)
		return (NULL);
	s = str;
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == 0)
		return (s);
	return (NULL);
}

char	*gnl_strlchr(char *str, char c, ssize_t len)
{
	char	*s;

	if (!str || len < 1)
		return (NULL);
	s = str;
	while (s - str < len && *s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

char	*gnl_strlcpy(char *str, ssize_t len)
{
	char	*cpy;
	ssize_t	i;

	if (!str || len < 1)
		return (NULL);
	cpy = malloc(len + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

char	*gnl_strlcat(char *s1, ssize_t len1, char *s2, ssize_t len2)
{
	char	*cat;
	ssize_t	i;

	if (!s1)
		return (NULL);
	if (!s2 || len2 < 1)
		return (s1);
	cat = malloc(len1 + len2 + 1);
	if (!cat)
		return (free(s1), NULL);
	i = 0;
	while (i < len1)
	{
		cat[i] = s1[i];
		i++;
	}
	while (i - len1 < len2)
	{
		cat[i] = s2[i - len1];
		i++;
	}
	cat[i] = 0;
	return (free(s1), s1 = NULL, cat);
}
