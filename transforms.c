/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:38:50 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/07 21:31:24 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	lerp(t_vec *v, const t_vec *w, double factor)
{
	v->re = w->re + factor * (v->re - w->re);
	v->im = w->im + factor * (v->im - w->im);
}

double	vnorm2(const t_vec *v)
{
	return (v->re * v->re + v->im * v->im);
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
