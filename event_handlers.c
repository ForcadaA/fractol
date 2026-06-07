/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:26:21 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/07 20:00:15 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	on_key_close(int keycode, t_vars *vars)
{
	if (keycode == e_escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	on_roll_zoom(int wheel, int x, int y, void *env)
{
	t_vec	p;
	t_data	*img;

	img = ((t_env *)env)->img;
	p.re = img->vmin->re + x * (img->vmax->re - img->vmin->re) / WX;
	p.im = img->vmin->im + y * (img->vmax->im - img->vmin->im) / WY;
	if (wheel == e_wheelup)
	{
		img->vmax->re = p.re + (img->vmax->re - p.re) / ZOOM;
		img->vmin->re = p.re - (p.re - img->vmin->re) / ZOOM;
		img->vmax->im = p.im + (img->vmax->im - p.im) / ZOOM;
		img->vmin->im = p.im - (p.im - img->vmin->im) / ZOOM;
	}
	if (wheel == e_wheeldown)
	{
		img->vmax->re = p.re + (img->vmax->re - p.re) * ZOOM;
		img->vmin->re = p.re - (p.re - img->vmin->re) * ZOOM;
		img->vmax->im = p.im + (img->vmax->im - p.im) * ZOOM;
		img->vmin->im = p.im - (p.im - img->vmin->im) * ZOOM;
	}
	return (draw((t_env *)env));
}

int	on_destroy_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}
