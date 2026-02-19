/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:26:04 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/19 17:05:20 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	mandelbrot_set(t_dataset *mdb, int x, int y)
{
	int			i;
	t_complex	z;
	t_complex	c;
	double		x2;
	double		y2;
	double		zn;
	double		nu;

	c.x = map((double)x, mdb->fract.min_x, mdb->fract.max_x, (double)W) - 0.5;
	c.y = map((double)y, mdb->fract.min_y, mdb->fract.max_y, (double)H);
	i = 0;
	z.x = 0;
	z.y = 0;
	x2 = 0;
	y2 = 0;
	while ((x2 * y2) <= 4.0 && i < mdb->fract.max_i)
	{
		z.y = (z.x + z.x) * z.y + c.y;
		z.x = x2 - y2 + c.x;
		x2 = z.x * z.x;
		y2 = z.y * z.y;
		i++;
	}
	if (i == mdb->fract.max_i)
		display_pixel(&mdb->mlx.frame, x, y, 0x000000);
	else
	{
		zn = x2 + y2;
		nu = log(log(zn) / 2.0) / log(2.0);
		display_pixel(&mdb->mlx.frame, x, y, hsv_to_rgb((i + 1 - nu) * 5, 1,
				1));
	}
}
