/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 21:35:39 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/07 21:40:58 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot(t_vec *v)
{
	t_vec	w;
	int		iter;

	iter = 0;
	w.re = 0;
	w.im = 0;
	while (vnorm2(&w) <= 4 && iter++ < MAX_ITER)
	{
		vsquare(&w);
		vadd(&w, v);
	}
	if (iter == MAX_ITER)
		return (0);
	return (iter);
}
