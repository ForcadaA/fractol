/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 23:48:18 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/07 16:08:12 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sign(const char *nptr, size_t i)
{
	if (nptr[i] == '-')
		return (-1);
	if (nptr[i] == '+')
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	if ('\t' <= c && c <= '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		n;
	int		sign;

	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	sign = ft_sign(nptr, i);
	if (sign != 0)
		i++;
	n = 0;
	while (ft_isdigit(nptr[i]))
		n = n * 10 + (nptr[i++] - '0');
	if (sign < 0)
		n = -n;
	return (n);
}
