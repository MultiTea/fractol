/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:26:04 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/19 12:25:49 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	fract_init(t_dataset *mdb)
{
	double	ratio;

	ratio = (double)W / (double)H;
	mdb->fract.min_y = -2.0;
	mdb->fract.max_y = 2.0;
	mdb->fract.min_x = -2.0 * ratio;
	mdb->fract.max_x = 2.0 * ratio;
	mdb->fract.max_i = 1000;
}

void	display_fract(t_dataset *fract, t_complex z, int x, int y, int i)
{
	double	zn;
	double	nu;

	if (i == fract->fract.max_i)
		display_pixel(&fract->mlx.frame, x, y, 0x000000);
	else
	{
		zn = z.x * z.x + z.y + z.y;
		nu = log(log(zn) / 2.0) / log(2.0);
		display_pixel(&fract->mlx.frame, x, y, hsv_to_rgb((i + 1 - nu) * 5, 1,
				1));
	}
}

double	map(double unscaled_num, double map_min, double map_max, double old_max)
{
	return ((map_max - map_min) * (unscaled_num / old_max) + map_min);
}

static void	mandelbrot_set(t_dataset *mdb, int x, int y)
{
	int			i;
	double		tmp;
	t_complex	z;
	t_complex	c;

	fract_init(mdb);
	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = map((double)x, mdb->fract.min_x, mdb->fract.max_x, (double)W) - 0.5;
	c.y = map((double)y, mdb->fract.min_y, mdb->fract.max_y, (double)H);
	while ((z.x * z.x + z.y + z.y) <= 4 && i < mdb->fract.max_i)
	{
		tmp = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = (2.0 * z.x * z.y) + c.y;
		z.x = tmp;
		i++;
	}
	display_fract(mdb, z, x, y, i);
}

int	render_mdb(t_dataset *mdb)
{
	int	y;
	int	x;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			mandelbrot_set(mdb, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mdb->mlx.mlx, mdb->mlx.win, mdb->mlx.frame.img, 0,
		0);
	return (0);
}
