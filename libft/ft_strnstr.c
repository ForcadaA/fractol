/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:17:33 by aforcada          #+#    #+#             */
/*   Updated: 2025/11/29 18:27:01 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	found;

	if (!(*little))
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		found = 1;
		while (i + j < len && little[j] && big[i + j])
		{
			if (big[i + j] != little[j])
				found = 0;
			j++;
		}
		if (found && j > 0 && !little[j])
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
