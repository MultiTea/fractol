/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 12:49:08 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/20 18:36:51 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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
	data->fract.max_i = 1000;
	data->k.up = 0;
	data->k.down = 0;
	data->k.right = 0;
	data->k.left = 0;
}

void	display_pixel(t_mlx_img *data, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || x < 0 || W < x || H < y)
		return ;
	dst = data->addr + (y * data->line_len + x * 4);
	*(unsigned int *)dst = color;
}

void	display_fract(t_dataset *fract, t_complex z, int x, int y, int i)
{
	double	zn;
	double	nu;

	if (i == fract->fract.max_i)
		display_pixel(&fract->mlx.frame, x, y, 0xFFFFFF);
	else
	{
		zn = z.x * z.x + z.y * z.y;
		nu = log2(log2(zn));
		display_pixel(&fract->mlx.frame, x, y, hsv_to_rgb((i + 1 - nu) * 5, 1,
				1));
	}
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
