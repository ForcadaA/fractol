/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_geom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 17:07:44 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/06 17:39:15 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_px(t_data *dat, int x, int y, int c)
{
	char	*dst;

	dst = dat->addr + (y * dat->line_length + x * (dat->bits_per_pixel / 8));
	*(unsigned int *)dst = c;
}
