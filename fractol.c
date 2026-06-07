/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 09:37:45 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/07 20:01:11 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_env(t_env *env, char *av[])
{
	static t_vars	vars;
	static t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WX, WY, "Fractol");
	img.img = mlx_new_image(vars.mlx, WX, WY);
	img.vseed = malloc(sizeof(double) * 2);
	img.vmin = malloc(sizeof(double) * 2);
	img.vmax = malloc(sizeof(double) * 2);
	img.vseed->re = ft_atof(av[1]);
	img.vseed->im = ft_atof(av[2]);
	img.vmin->re = REAL_MIN;
	img.vmin->im = IMAG_MIN;
	img.vmax->re = REAL_MAX;
	img.vmax->im = IMAG_MAX;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	env->img = &img;
	env->mlx = &vars;
}

int	main(int ac, char *av[])
{
	t_env	env;

	if (ac != 3)
		err_default();
	ft_init_env(&env, av);
	ft_putstr_fd("ok\n", 1);
	mlx_mouse_hook(env.mlx->win, on_roll_zoom, &env);
	mlx_hook(env.mlx->win, e_on_keydown,
		e_key_press_mask, on_key_close, env.mlx);
	mlx_hook(env.mlx->win, e_on_destroy,
		e_no_event_mask, on_destroy_close, env.mlx);
	mlx_loop(env.mlx->mlx);
	return (0);
}
