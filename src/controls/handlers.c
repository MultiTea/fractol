/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:31:04 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/19 18:02:47 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	key_handler(int keycode, t_dataset *graphic)
{
	double	shift;

	shift = (graphic->fract.max_x - graphic->fract.min_x) * 0.1;
	if (keycode == ESC)
	{
		close_hook(graphic);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == ARR_UP)
	{
		graphic->fract.min_y += shift;
		graphic->fract.max_y += shift;
	}
	else if (keycode == ARR_DOWN)
	{
		graphic->fract.min_y -= shift;
		graphic->fract.max_y -= shift;
	}
	else if (keycode == ARR_L)
	{
		graphic->fract.min_x += shift;
		graphic->fract.max_x += shift;
	}
	else if (keycode == ARR_L)
	{
		graphic->fract.min_x -= shift;
		graphic->fract.max_x -= shift;
	}
	render_fract(graphic);
	return (0);
}
