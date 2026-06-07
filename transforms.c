/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:38:50 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/07 16:50:01 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	vnorm2(t_vec v)
{
	return (v.re * v.re + v.im * v.im);
}

void	vsquare(t_vec *v)
{
	double	tmp;

	tmp = v->re * v->re - v->im * v->im;
	v->im = 2 * v->re * v->im;
	v->re = tmp;
}

void	vadd(t_vec *v, const t_vec *w)
{
	v->re += w->re;
	v->im += w->im;
}

int	julia(t_vec v, const t_vec *vseed)
{
	int		iter;

	iter = 0;
	while (vnorm2(v) <= 4 && iter++ < MAX_ITER)
	{
		vsquare(&v);
		vadd(&v, vseed);
	}
	if (iter == MAX_ITER)
		return (0);
	return (iter);
}
