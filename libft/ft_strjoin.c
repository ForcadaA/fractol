/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:01:13 by aforcada          #+#    #+#             */
/*   Updated: 2025/11/29 20:42:24 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s = malloc(len1 + len2 + 1);
	if (!s)
		return (NULL);
	i = -1;
	while (++i < len1)
		s[i] = s1[i];
	while (i++ - len1 < len2)
		s[i - 1] = s2[i - 1 - len1];
	s[i - 1] = '\0';
	return (s);
}
