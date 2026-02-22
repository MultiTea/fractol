/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:25:59 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/22 19:47:03 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

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

	shift = (graphic->fract.x.max - graphic->fract.x.min) * 0.05;
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
	double	new_range_x;
	double	new_range_y;

	new_range_x = (graphic->fract.x.max - graphic->fract.x.min) * zoom_ratio;
	new_range_y = (graphic->fract.y.max - graphic->fract.y.min) * zoom_ratio;
	graphic->fract.x.min = mouse_reel - (mouse_reel - graphic->fract.x.min)
		* zoom_ratio;
	graphic->fract.x.max = graphic->fract.x.min + new_range_x;
	graphic->fract.y.min = mouse_img - (mouse_img - graphic->fract.y.min)
		* zoom_ratio;
	graphic->fract.y.max = graphic->fract.y.min + new_range_y;
}

int	mouse_handler(int button, int x, int y, t_dataset *graphic)
{
	double	mouse_reel;
	double	mouse_img;

	if (button == 4 || button == 5)
	{
		mouse_reel = graphic->fract.x.min + (double)x * (graphic->fract.x.max
				- graphic->fract.x.min) / W;
		mouse_img = graphic->fract.y.max - (double)y * (graphic->fract.y.max
				- graphic->fract.y.min) / H;
		if (button == 4)
			zoom_handler(graphic, mouse_reel, mouse_img, 0.90);
		else if (button == 5)
			zoom_handler(graphic, mouse_reel, mouse_img, 1.10);
	}
	graphic->is_rendered = 0;
	return (0);
}
