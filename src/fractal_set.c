/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:26:04 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/22 00:37:54 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static double	map(double unscaled_num, double map_min, double map_max,
		double old_max)
{
	return ((map_max - map_min) * (unscaled_num / old_max) + map_min);
}

static void	init_mandelbrot_args(t_dataset *mdb, double *x2, double *y2)
{
	if (mdb->fract.type == MANDELBROT)
	{
		mdb->c.x = map((double)mdb->p.x, mdb->fract.x.min, mdb->fract.x.max,
				(double)W) - 0.5;
	}
	else
		mdb->c.x = map((double)mdb->p.x, mdb->fract.x.min, mdb->fract.x.max,
				(double)W);
	mdb->c.y = map((double)mdb->p.y, mdb->fract.y.max, mdb->fract.y.min,
			(double)H);
	mdb->z.x = 0.0;
	mdb->z.y = 0.0;
	*x2 = 0;
	*y2 = 0;
}

void	mandelbrot_set(t_dataset *mdb, double x2, double y2)
{
	mdb->fract.i = 0;
	mdb->fract.mb.old_x = 0;
	mdb->fract.mb.old_y = 0;
	mdb->fract.mb.period = 0;
	init_mandelbrot_args(mdb, &x2, &y2);
	while ((x2 + y2) <= 4.0 && mdb->fract.i < mdb->fract.max_i)
	{
		mdb->z.y = 2.0 * mdb->z.x * mdb->z.y + mdb->c.y;
		mdb->z.x = x2 - y2 + mdb->c.x;
		x2 = mdb->z.x * mdb->z.x;
		y2 = mdb->z.y * mdb->z.y;
		mdb->fract.i++;
		if (mdb->z.x == mdb->fract.mb.old_x && mdb->z.y == mdb->fract.mb.old_y)
			mdb->fract.i = mdb->fract.max_i;
		if (++mdb->fract.mb.period > 20)
		{
			mdb->fract.mb.period = 0;
			mdb->fract.mb.old_x = mdb->z.x;
			mdb->fract.mb.old_y = mdb->z.y;
		}
	}
	display_fract(mdb, mdb->fract.i);
}

void	multibrot_set(t_dataset *mdb, double x2, double y2)
{
	double	tmp_x;

	mdb->fract.i = 0;
	mdb->fract.mb.old_x = 0;
	mdb->fract.mb.old_y = 0;
	mdb->fract.mb.period = 0;
	init_mandelbrot_args(mdb, &x2, &y2);
	while ((x2 + y2) <= 4.0 && mdb->fract.i < mdb->fract.max_i)
	{
		tmp_x = (x2 * x2) - (6.0 * x2 * y2) + (y2 * y2) + mdb->c.x;
		mdb->z.y = 4.0 * mdb->z.x * mdb->z.y * (x2 - y2) + mdb->c.y;
		mdb->z.x = tmp_x;
		x2 = mdb->z.x * mdb->z.x;
		y2 = mdb->z.y * mdb->z.y;
		mdb->fract.i++;
		if (mdb->z.x == mdb->fract.mb.old_x && mdb->z.y == mdb->fract.mb.old_y)
			mdb->fract.i = mdb->fract.max_i;
		if (++mdb->fract.mb.period > 20)
		{
			mdb->fract.mb.period = 0;
			mdb->fract.mb.old_x = mdb->z.x;
			mdb->fract.mb.old_y = mdb->z.y;
		}
	}
	display_fract(mdb, mdb->fract.i);
}

void	julia_set(t_dataset *julia)
{
	double	tmp;

	julia->fract.i = 0;
	julia->z.x = map((double)julia->p.x, julia->fract.x.min, julia->fract.x.max,
			(double)W);
	julia->z.y = map((double)julia->p.y, julia->fract.y.max, julia->fract.y.min,
			(double)H);
	julia->c.x = julia->fract.j.reel;
	julia->c.y = julia->fract.j.img;
	while (julia->fract.i < julia->fract.max_i)
	{
		if ((julia->z.x * julia->z.x + julia->z.y * julia->z.y) > 4.0)
			break ;
		tmp = (julia->z.x * julia->z.x) - (julia->z.y * julia->z.y);
		julia->z.y = 2 * julia->z.x * julia->z.y + julia->c.y;
		julia->z.x = tmp + julia->c.x;
		julia->fract.i++;
	}
	display_fract(julia, julia->fract.i);
}

void	display_fract(t_dataset *fract, int i)
{
	int		color;
	double	zn;
	double	nu;
	int		gradient;

	if (i == fract->fract.max_i)
		display_pixel(&fract->mlx.frame, fract->p.x, fract->p.y, 0x000000);
	else
	{
		zn = fract->z.x * fract->z.x + fract->z.y * fract->z.y;
		nu = log2(log2(zn));
		gradient = i + 1 - nu;
		color = 0;
		fract->max_ite = 360;
		if (fract->anim == STATIC)
			color = hsv_to_rgb(gradient, 1, 1);
		else if (fract->anim == ANIMATED)
			color = hsv_animate(fract, gradient * fract->ite);
		display_pixel(&fract->mlx.frame, fract->p.x, fract->p.y, color);
	}
}
