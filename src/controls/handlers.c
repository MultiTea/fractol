/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:31:04 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/20 17:09:10 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	key_handler(t_dataset *graphic)
{
	double	shift;

	shift = (graphic->fract.max_x - graphic->fract.min_x) * 0.1;
	if (graphic->k.up)
	{
		graphic->fract.min_y -= shift;
		graphic->fract.max_y -= shift;
	}
	else if (graphic->k.down)
	{
		graphic->fract.min_y += shift;
		graphic->fract.max_y += shift;
	}
	else if (graphic->k.right)
	{
		graphic->fract.min_x += shift;
		graphic->fract.max_x += shift;
	}
	else if (graphic->k.left)
	{
		graphic->fract.min_x -= shift;
		graphic->fract.max_x -= shift;
	}
	render_fract(graphic);
	mlx_put_image_to_window(graphic->mlx.mlx, graphic->mlx.win,
		graphic->mlx.frame.img, 0, 0);
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
}

int	mouse_handler(int button, int x, int y, t_dataset *graphic)
{
	double	mouse_reel;
	double	mouse_img;
	double	zoom_ratio;

	if (button == 4 || button == 5)
	{
		mouse_reel = graphic->fract.min_x + (double)x * (graphic->fract.max_x
				- graphic->fract.min_x) / W;
		mouse_img = graphic->fract.min_y + (double)y * (graphic->fract.max_y
				- graphic->fract.min_y) / H;
		if (button == 4)
			zoom_ratio = 0.90;
		else
			zoom_ratio = 1.10;
		zoom_handler(graphic, mouse_reel, mouse_img, zoom_ratio);
	}
	return (0);
}
