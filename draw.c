/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:03:19 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/08 11:44:46 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	color(int val)
{
	return (e_red + (double)val / MAX_ITER * (e_cadetblue - e_red));
}

static int	get_col(t_vec *v, t_env *env)
{
	t_data	img;

	img = env->img;
	if (env->set == 'j')
		return (julia(v, img.vseed));
	if (env->set == 'm')
		return (mandelbrot(v));
	if (env->set == 'd')
		return (douaby(v));
	return (0);
}

void	draw(t_env *env)
{
	t_vec	v;
	t_pos	p;
	t_data	img;
	int		col;

	p.y = WY;
	img = env->img;
	while (p.y--)
	{
		p.x = 0;
		while (p.x++ < WX)
		{
			v.re = img.vmin->re + p.x * (img.vmax->re - img.vmin->re) / WX;
			v.im = img.vmin->im + p.y * (img.vmax->re - img.vmin->re) / WX;
			col = get_col(&v, env);
			put_px(&img, p.x, p.y, color(col));
		}
	}
	mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, img.img, 0, 0);
}
