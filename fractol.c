/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 09:37:45 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/07 18:17:57 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	on_roll_zoom(int roll, int x, int y, void *e);

void	transform(t_data *img)
{
	(void)img;
}

int	color(int val)
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
	return (mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0));
}

int	main(int ac, char *av[])
{
	t_vars	vars;
	t_data	img;
	t_env	env;

	if (ac != 3)
		err_default();
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WX, WY, "Hello world!");
	img.img = mlx_new_image(vars.mlx, WX, WY);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);
	img.vseed->re = ft_atof(av[1]);
	img.vseed->im = ft_atof(av[2]);
	img.vmin->re = REAL_MIN;
	img.vmin->im = IMAG_MIN;
	img.vmax->re = REAL_MAX;
	img.vmax->im = IMAG_MAX;
	env.mlx = &(vars.mlx);
	env.win = &(vars.win);
	env.img = &img;
	mlx_mouse_hook(vars.win, on_roll_zoom, &env);
	mlx_hook(vars.win, e_on_keydown, e_key_press_mask, on_key_close, &vars);
	mlx_hook(vars.win, e_on_destroy, e_no_event_mask, on_destroy_close, &vars);
	mlx_loop(vars.mlx);
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