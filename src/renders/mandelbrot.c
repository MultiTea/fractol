/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:26:04 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/20 13:01:12 by lbolea           ###   ########.fr       */
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

	c.x = map((double)x, mdb->fract.min_x, mdb->fract.max_x, (double)W) - 0.5;
	c.y = map((double)y, mdb->fract.min_y, mdb->fract.max_y, (double)H);
	i = 0;
	z.x = 0;
	z.y = 0;
	x2 = 0;
	y2 = 0;
	while ((x2 + y2) <= 4.0 && i < mdb->fract.max_i)
	{
		z.y = 2 * z.x * z.y + c.y;
		z.x = x2 - y2 + c.x;
		x2 = z.x * z.x;
		y2 = z.y * z.y;
		i++;
	}
	display_fract(mdb, z, x, y, i);
}
