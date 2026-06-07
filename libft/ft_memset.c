/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:38:02 by aforcada          #+#    #+#             */
/*   Updated: 2025/11/30 15:12:00 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	cast_c;
	char	*cast_s;

	i = 0;
	cast_c = c;
	cast_s = s;
	while (i < n)
		cast_s[i++] = cast_c;
	return (s);
}
