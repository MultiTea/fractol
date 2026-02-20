/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:26:04 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/20 20:42:56 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static double	map(double unscaled_num, double map_min, double map_max,
		double old_max)
{
	return ((map_max - map_min) * (unscaled_num / old_max) + map_min);
}

void	multibrot_set(t_dataset *mdb, t_pos p)
{
	int			i;
	t_complex	z;
	t_complex	c;
	double		x2;
	double		y2;
	double		xtemp;
	double		xold;
	double		yold;
	int			period;

	i = 0;
	c.x = map((double)p.x, mdb->fract.min_x, mdb->fract.max_x, (double)W);
	c.y = map((double)p.y, mdb->fract.min_y, mdb->fract.max_y, (double)H);
	z.x = 0;
	z.y = 0;
	x2 = 0;
	y2 = 0;
	xold = 0;
	yold = 0;
	period = 0;
	while ((x2 + y2) <= 4.0 && i < mdb->fract.max_i)
	{
		xtemp = (x2 * x2) - (6.0 * x2 * y2) + (y2 * y2) + c.x;
		z.y = (4.0 * z.x * z.x * z.x * z.y) - (4.0 * z.x * z.y * z.y * z.y)
			+ c.y;
		z.x = xtemp;
		x2 = z.x * z.x;
		y2 = z.y * z.y;
		i++;
		if (z.x == xold && z.y == yold)
		{
			i = mdb->fract.max_i;
			break ;
		}
		period++;
		if (period > 20)
		{
			period = 0;
			xold = z.x;
			yold = z.y;
		}
	}
	display_fract(mdb, z, p, i);
}

void	mandelbrot_set(t_dataset *mdb, t_pos p)
{
	int			i;
	t_complex	z;
	t_complex	c;
	double		x2;
	double		y2;
	double		xold;
	double		yold;
	int			period;

	i = 0;
	c.x = map((double)p.x, mdb->fract.min_x, mdb->fract.max_x, (double)W) - 0.5;
	c.y = map((double)p.y, mdb->fract.min_y, mdb->fract.max_y, (double)H);
	z.x = 0;
	z.y = 0;
	x2 = 0;
	y2 = 0;
	xold = 0;
	yold = 0;
	period = 0;
	while ((x2 + y2) <= 4.0 && i < mdb->fract.max_i)
	{
		z.y = 2.0 * z.x * z.y + c.y;
		z.x = x2 - y2 + c.x;
		x2 = z.x * z.x;
		y2 = z.y * z.y;
		i++;
		if (z.x == xold && z.y == yold)
		{
			i = mdb->fract.max_i;
			break ;
		}
		period++;
		if (period > 20)
		{
			period = 0;
			xold = z.x;
			yold = z.y;
		}
	}
	display_fract(mdb, z, p, i);
}

void	julia_set(t_dataset *julia, t_pos p)
{
	int			i;
	double		tmp;
	t_complex	z;
	t_complex	c;

	i = 0;
	z.x = map((double)p.x, julia->fract.min_x, julia->fract.max_x, (double)W);
	z.y = map((double)p.y, julia->fract.min_y, julia->fract.max_y, (double)H);
	c.x = julia->fract.julia_x;
	c.y = julia->fract.julia_y;
	while (i < julia->fract.max_i)
	{
		if ((z.x * z.x + z.y * z.y) > 4.0)
			break ;
		tmp = (z.x * z.x) - (z.y * z.y);
		z.y = 2 * z.x * z.y + c.y;
		z.x = tmp + c.x;
		i++;
	}
	display_fract(julia, z, p, i);
}

void	display_fract(t_dataset *fract, t_complex z, t_pos p, int i)
{
	int		color;
	double	zn;
	double	nu;

	(void)z;
	if (i == fract->fract.max_i)
		display_pixel(&fract->mlx.frame, p.x, p.y, 0x000000);
	else
	{
		zn = z.x * z.x + z.y * z.y;
		nu = log2(log2(zn));
		color = hsv_to_rgb((i + 1 - nu) * 5, 1, 1);
		display_pixel(&fract->mlx.frame, p.x, p.y, color);
	}
}
