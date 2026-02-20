/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:26:04 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/20 18:35:40 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static double	map(double unscaled_num, double map_min, double map_max,
		double old_max)
{
	return ((map_max - map_min) * (unscaled_num / old_max) + map_min);
}

void	mandelbrot_set(t_dataset *mdb, int x, int y)
{
	int			i;
	t_complex	z;
	t_complex	c;
	double		x2;
	double		y2;

	i = 0;
	c.x = map((double)x, mdb->fract.min_x, mdb->fract.max_x, (double)W) - 0.5;
	c.y = map((double)y, mdb->fract.min_y, mdb->fract.max_y, (double)H);
	z.x = 0;
	z.y = 0;
	x2 = 0;
	y2 = 0;
	while ((x2 + y2) <= 4.0 && i < mdb->fract.max_i)
	{
		z.y = 2.0 * z.x * z.y + c.y;
		z.x = x2 - y2 + c.x;
		x2 = z.x * z.x;
		y2 = z.y * z.y;
		i++;
	}
	display_fract(mdb, z, x, y, i);
}

void	julia_set(t_dataset *julia, int x, int y)
{
	int			i;
	double		tmp;
	t_complex	z;
	t_complex	c;

	i = 0;
	z.x = map((double)x, julia->fract.min_x, julia->fract.max_x, (double)W);
	z.y = map((double)y, julia->fract.min_y, julia->fract.max_y, (double)H);
	c.x = julia->fract.julia_x;
	c.y = julia->fract.julia_y;
	while (i < julia->fract.max_i)
	{
		if ((z.x * z.x + z.y * z.y) > 4)
			break ;
		tmp = (z.x * z.x) - (z.y * z.y);
		z.y = 2 * z.x * z.y + c.y;
		z.x = tmp + c.x;
		i++;
	}
	display_fract(julia, z, x, y, i);
}
