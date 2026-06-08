/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 09:37:45 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/08 11:48:06 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_input(int ac, char *av[])
{
	if (ac == 2 && (av[1])[0] == 'm' && ft_strlen(av[1]) == 1)
	{
		return ;
	}
	if (ac == 2 && (av[1])[0] == 'd' && ft_strlen(av[1]) == 1)
	{
		return ;
	}
	if (ac == 4 && (av[1])[0] == 'j' && ft_strlen(av[1]) == 1
		&& ft_isfloat(av[2])
		&& ft_isfloat(av[3]))
	{
		return ;
	}
	err_default(" Use: ./fractol <d/j/m> [j:<re> <im>]");
}

void	init_img(t_data *img, int ac, char *av[])
{
	img->vseed = malloc(sizeof(double) * 2);
	img->vmin = malloc(sizeof(double) * 2);
	img->vmax = malloc(sizeof(double) * 2);
	if (!(img->vseed) || !(img->vmax) || !(img->vmin))
		err_init_fail(img);
	if (ac == 4)
	{
		img->vseed->re = ft_atof(av[2]);
		img->vseed->im = ft_atof(av[3]);
	}
	img->vmin->re = REAL_MIN;
	img->vmin->im = IMAG_MIN;
	img->vmax->re = REAL_MAX;
	img->vmax->im = IMAG_MAX;
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
}

void	init_env(t_env *env, int ac, char *av[])
{
	env->mlx.mlx = mlx_init();
	env->mlx.win = mlx_new_window(env->mlx.mlx, WX, WY, "Fractol");
	env->img.img = mlx_new_image(env->mlx.mlx, WX, WY);
	init_img(&env->img, ac, av);
	env->set = *(av[1]);
}

int	main(int ac, char *av[])
{
	t_env	env;

	check_input(ac, av);
	init_env(&env, ac, av);
	draw(&env);
	mlx_mouse_hook(env.mlx.win, on_roll_zoom, &env);
	mlx_hook(env.mlx.win, e_on_keydown,
		e_key_press_mask, on_key_close, &env);
	mlx_hook(env.mlx.win, e_on_destroy,
		e_no_event_mask, on_destroy_close, &env);
	mlx_loop(env.mlx.mlx);
	return (0);
}
