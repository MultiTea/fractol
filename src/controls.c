/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:25:59 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/22 15:22:59 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	key_pressed(int keycode, t_dataset *graphic)
{
	if (keycode == ESC)
	{
		close_hook(graphic);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == ARR_UP)
		graphic->k.up = 1;
	else if (keycode == ARR_DOWN)
		graphic->k.down = 1;
	else if (keycode == ARR_R)
		graphic->k.right = 1;
	else if (keycode == ARR_L)
		graphic->k.left = 1;
	return (0);
}

int	key_released(int keycode, t_dataset *graphic)
{
	if (keycode == ARR_UP)
		graphic->k.up = 0;
	else if (keycode == ARR_DOWN)
		graphic->k.down = 0;
	else if (keycode == ARR_R)
		graphic->k.right = 0;
	else if (keycode == ARR_L)
		graphic->k.left = 0;
	return (0);
}

int	key_handler(t_dataset *graphic)
{
	double	shift;

	shift = (graphic->fract.x.max - graphic->fract.x.min) * 0.005;
	if (graphic->k.up)
	{
		graphic->fract.y.min += shift;
		graphic->fract.y.max += shift;
	}
	else if (graphic->k.down)
	{
		graphic->fract.y.min -= shift;
		graphic->fract.y.max -= shift;
	}
	else if (graphic->k.right)
	{
		graphic->fract.x.min += shift;
		graphic->fract.x.max += shift;
	}
	else if (graphic->k.left)
	{
		graphic->fract.x.min -= shift;
		graphic->fract.x.max -= shift;
	}
	graphic->is_rendered = 0;
	return (0);
}

static void	zoom_handler(t_dataset *graphic, double mouse_reel,
		double mouse_img, double zoom_ratio)
{
	double	curr_width;
	double	curr_height;
	double	new_width;
	double	new_height;

	curr_width = graphic->fract.x.max - graphic->fract.x.min;
	curr_height = graphic->fract.y.max - graphic->fract.y.min;
	new_width = curr_width * zoom_ratio;
	new_height = curr_height * zoom_ratio;
	graphic->fract.x.min = mouse_reel - (mouse_reel - graphic->fract.x.min)
		* zoom_ratio;
	graphic->fract.x.max = graphic->fract.x.min + new_width;
	graphic->fract.y.min = mouse_img - (mouse_img - graphic->fract.y.min)
		* zoom_ratio;
	graphic->fract.y.max = graphic->fract.y.min + new_height;
}

int	mouse_handler(int button, int x, int y, t_dataset *graphic)
{
	double	mouse_reel;
	double	mouse_img;
	double	zoom_ratio;

	if (button == 4 || button == 5)
	{
		mouse_reel = graphic->fract.x.min + (double)x * (graphic->fract.x.max
				- graphic->fract.x.min) / W;
		mouse_img = graphic->fract.y.max - (double)y * (graphic->fract.y.max
				- graphic->fract.y.min) / H;
		if (button == 4)
			zoom_ratio = 0.90;
		else
			zoom_ratio = 1.10;
		zoom_handler(graphic, mouse_reel, mouse_img, zoom_ratio);
	}
	graphic->is_rendered = 0;
	return (0);
}
