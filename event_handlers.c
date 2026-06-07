/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:26:21 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/07 21:26:14 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static void	free_img_vectors(t_env *env)
{
	free(env->img->vseed);
	free(env->img->vmax);
	free(env->img->vmin);
}

int	on_key_close(int keycode, t_env *env)
{
	if (keycode == e_escape)
	{
		free_img_vectors(env);
		mlx_destroy_window(env->mlx->mlx, env->mlx->win);
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
		lerp(img->vmax, &p, 1. / ZOOM);
		lerp(img->vmin, &p, 1. / ZOOM);
		draw((t_env *)env);
	}
	if (wheel == e_wheeldown)
	{
		lerp(img->vmax, &p, ZOOM);
		lerp(img->vmin, &p, ZOOM);
		draw((t_env *)env);
	}
	return (0);
}

int	on_destroy_close(t_env *env)
{
	free_img_vectors(env);
	mlx_destroy_window(env->mlx->mlx, env->mlx->win);
	exit(0);
	return (0);
}
