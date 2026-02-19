/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:31:04 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/19 18:38:41 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	key_handler(int keycode, t_dataset *graphic)
{
	double	shift;

	shift = (graphic->fract.max_x - graphic->fract.min_x) * 0.015;
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

static void	zoom_handler(t_dataset *graphic, double mouse_reel,
		double mouse_img, double zoom_ratio)
{
	double	curr_width;
	double	curr_height;
	double	new_width;
	double	new_height;

	curr_width = graphic->fract.max_x - graphic->fract.min_x;
	curr_height = graphic->fract.max_y - graphic->fract.min_y;
	new_width = curr_width * zoom_ratio;
	new_height = curr_height * zoom_ratio;
	graphic->fract.min_x = mouse_reel - (mouse_reel - graphic->fract.min_x)
		* zoom_ratio;
	graphic->fract.max_x = graphic->fract.min_x + new_width;
	graphic->fract.min_y = mouse_img - (mouse_img - graphic->fract.min_y)
		* zoom_ratio;
	graphic->fract.max_y = graphic->fract.min_y + new_height;
	render_fract(graphic);
}

int	mouse_handler(int button, int x, int y, t_dataset *graphic)
{
	double	mouse_reel;
	double	mouse_img;
	double	zoom;
	double	zoom_ratio;

	if (button == 4 || button == 5)
	{
		mouse_reel = map((double)x, graphic->fract.min_x, graphic->fract.max_x,
				W);
		mouse_img = map((double)y, graphic->fract.max_y, graphic->fract.min_y,
				H);
		if (button == 4)
			zoom = 1.1;
		else
			zoom = 0.9;
		zoom_ratio = 1.0 / zoom;
		zoom_handler(graphic, mouse_reel, mouse_img, zoom_ratio);
	}
	return (0);
}
