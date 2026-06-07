/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 16:04:22 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/07 22:08:18 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static float	ft_atodec(const char *s)
{
	float	dec;
	float	prec;

	dec = 0;
	prec = 0.1;
	while (ft_isdigit(*s))
	{
		dec += prec * (*s++ - '0');
		prec = prec * 0.1;
	}
	return (dec);
}

float	ft_atof(const char *s)
{
	float	n;
	int		sign;

	while (ft_isspace(*s))
		s++;
	sign = ft_sign(s, 0);
	if (sign)
		s++;
	n = 0;
	while (ft_isdigit(*s))
		n = n * 10 + (*s++ - '0');
	if (*s == '.')
		n += ft_atodec(s + 1);
	if (sign)
		n = sign * n;
	return (n);
}

int	ft_isfloat(const char *s)
{
	int		sign;

	if (!s)
		return (0);
	while (ft_isspace(*s))
		s++;
	sign = ft_sign(s, 0);
	if (sign)
		s++;
	while (ft_isdigit(*s))
		s++;
	if (*s == '.')
		s++;
	while (ft_isdigit(*s))
		s++;
	if (*s)
		return (0);
	return (1);
}
