/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 12:49:08 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/19 17:06:59 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	fract_init(t_dataset *data)
{
	double	ratio;

	ratio = (double)W / (double)H;
	data->fract.min_y = -2.0;
	data->fract.max_y = 2.0;
	data->fract.min_x = -2.0 * ratio;
	data->fract.max_x = 2.0 * ratio;
	data->fract.julia_x = 0.001643721971153;
	data->fract.julia_y = 0.822467633298876;
	data->fract.max_i = 100;
}

void	display_fract(t_dataset *fract, t_complex z, int x, int y, int i)
{
	double	zn;
	double	nu;

	if (i == fract->fract.max_i)
		display_pixel(&fract->mlx.frame, x, y, 0x000000);
	else
	{
		zn = z.x * z.x + z.y * z.y;
		nu = log(log(zn) / 2.0) / log(2.0);
		display_pixel(&fract->mlx.frame, x, y, hsv_to_rgb((i + 1 - nu) * 5, 1,
				1));
	}
}

double	map(double unscaled_num, double map_min, double map_max, double old_max)
{
	return ((map_max - map_min) * (unscaled_num / old_max) + map_min);
}

int	render_fract(t_dataset *fract)
{
	int	y;
	int	x;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			if (fract->fract.type == MANDELBROT)
				mandelbrot_set(fract, x, y);
			else if (fract->fract.type == JULIA)
				julia_set(fract, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx.mlx, fract->mlx.win,
		fract->mlx.frame.img, 0, 0);
	return (0);
}
