/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 21:30:35 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/07 21:39:36 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_vec *v, const t_vec *vseed)
{
	int		iter;

	iter = 0;
	while (vnorm2(v) <= 4 && iter++ < MAX_ITER)
	{
		vsquare(v);
		vadd(v, vseed);
	}
	if (iter == MAX_ITER)
		return (0);
	return (iter);
}
