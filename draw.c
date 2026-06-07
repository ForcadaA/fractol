/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:03:19 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/07 23:04:47 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	color(int val)
{
	return (e_red + (double)val / MAX_ITER * (e_cadetblue - e_red));
}

void	draw(t_env *env)
{
	t_vec	v;
	t_pos	p;
	t_data	*img;
	int		col;

	p.y = WY;
	img = env->img;
	while (p.y--)
	{
		p.x = 0;
		while (p.x++ < WX)
		{
			v.re = img->vmin->re + p.x * (img->vmax->re - img->vmin->re) / WX;
			v.im = img->vmin->im + p.y * (img->vmax->im - img->vmin->im) / WY;
			if (env->set == 'j')
				col = julia(&v, img->vseed);
			else if (env->set == 'm')
				col = mandelbrot(&v);
			else
				col = 0;
			put_px(img, p.x, p.y, color(col));
		}
	}
	mlx_put_image_to_window(env->mlx->mlx, env->mlx->win, img->img, 0, 0);
}
