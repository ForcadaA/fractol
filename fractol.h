/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 00:47:52 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/07 18:02:05 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define _XOPEN_SOURCE 500
# define WX 1500
# define WY 900
# define ZOOM 3.5
# define REAL_MIN -2.0
# define REAL_MAX 2.0
# define IMAG_MIN -1.0
# define IMAG_MAX 1.0
# define MAX_ITER 63

# include <fcntl.h>
# include <stdlib.h>
# include <sys/time.h>
# include <math.h>
# include "./libft/libft.h"
# include "./mlx/mlx.h"

typedef struct s_data	t_data;
typedef struct s_vars	t_vars;
typedef struct s_env	t_env;
typedef unsigned int	t_uint;
typedef struct s_vec	t_vec;
typedef struct s_pos	t_pos;

struct s_env
{
	void	*mlx;
	void	*win;
	void	*img;
};


struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_vec	*vseed;
	t_vec	*vmax;
	t_vec	*vmin;
};

struct s_vars
{
	void	*mlx;
	void	*win;
};

struct s_vec
{
	double	re;
	double	im;
};

struct s_pos
{
	int	x;
	int	y;
};

enum e_event_hooks
{
	e_on_keydown = 2,
	e_on_keyup = 3,
	e_on_mousedown = 4,
	e_on_mouseup = 5,
	e_on_mousemove = 6,
	e_on_expose = 12,
	e_on_destroy = 17,
};

enum e_event_masks
{
	e_no_event_mask = 0L,
	e_key_press_mask = (1L<<0),
	e_key_release_mask = (1L<<1),
	e_button_press_mask = (1L<<2),
	e_button_release_mask = (1L<<3),
	e_enter_window_mask = (1L<<4),
	e_leave_window_mask = (1L<<5),
	e_pointer_motion_mask = (1L<<6),
	e_pointer_motion_hint_mask = (1L<<7),
	e_button1_motion_mask = (1L<<8),
	e_button2_motion_mask = (1L<<9),
	e_button3_motion_mask = (1L<<10),
	e_button4_motion_mask = (1L<<11),
	e_button5_motion_mask = (1L<<12),
	e_button_motion_mask = (1L<<13),
	e_keymap_state_mask = (1L<<14),
	e_exposure_mask = (1L<<15),
	e_visibility_change_mask = (1L<<16),
	e_structure_notify_mask = (1L<<17),
	e_resize_redirect_mask = (1L<<18),
	e_substructure_notify_mask = (1L<<19),
	e_substructure_redirect_mask = (1L<<20),
	e_focus_change_mask = (1L<<21),
	e_property_change_mask = (1L<<22),
	e_colormap_change_mask = (1L<<23),
	e_owner_grab_button_mask = (1L<<24),
};

enum e_keycodes
{
	e_escape = 0xFF1B,
	e_wheelup = 4,
	e_wheeldown = 5,
};

enum e_colorcodes
{
	e_red = 0x00FF0000,
	e_green = 0x0000FF00,
	e_blue = 0x000000FF,
	e_yellow = 0x00FFFF00,
	e_purple = 0x00FF00FF,
	e_cyan = 0x0000FFFF,
};

//========================================================//
//                     EVENT HANDLERS                     //
//========================================================//
int		on_key_close(int keycode, t_vars *vars);
int		on_destroy_close(t_vars *vars);
// ====================================================== //
//                     DRAW & TRANSFORMS                  //
// ====================================================== //
void	put_px(t_data *dat, int x, int y, int c);
void	err_default(void);
float	ft_atof(const char *s);
int		julia(t_vec v, const t_vec *vseed);

#endif
