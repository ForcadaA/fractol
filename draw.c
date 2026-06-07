/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:03:19 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/07 19:59:40 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	color(int val)
{
	return (e_yellow / MAX_ITER * val);
}

int	draw(t_env *env)
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
			col = julia(v, img->vseed);
			put_px(img, p.x, p.y, color(col));
		}
	}
	return (mlx_put_image_to_window(env->mlx->mlx, env->mlx->win,
			env->img->img, 0, 0));
}
