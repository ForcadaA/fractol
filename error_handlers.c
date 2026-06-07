/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 15:58:19 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/07 20:27:53 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	err_default(char *msg)
{
	ft_putstr_fd("Error", STDERR_FILENO);
	if (msg)
		ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(1);
}

void	err_init_fail(t_data *img)
{
	free(img);
	err_default(": init failure");
}
