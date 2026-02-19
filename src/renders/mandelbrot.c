/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:26:04 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/19 10:56:51 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	mandelbrot_set(t_dataset *mdb, t_pixel p)
{
	static int	i = 0;
	int			color;
	double		x0;
	double		y0;
	double		xtemp;
	double		log_zn;
	double		nu;
	double		cu;

	x0 = 0;
	y0 = 0;
	p.x = 0;
	p.y = 0;
	cu = 0;
	mdb->fract.max_i = 500;
	while (p.x * p.x + p.y * p.y <= (1 << 16) && i < mdb->fract.max_i)
	{
		xtemp = p.x * p.x + x0;
		p.y = 2 * p.x * p.y + y0;
		p.x = xtemp;
		i++;
	}
	if (i < mdb->fract.max_i)
	{
		log_zn = log(p.x * p.x + p.y * p.y) / 2;
		nu = log(log_zn / log(2)) / 2;
		cu = i + 1 - nu;
	}
	color = hsv_to_rgb(cu * 360.0, 1.0, 1.0);
	display_pixel(&mdb->mlx.frame, p.x, p.y, color);
	mlx_put_image_to_window(&mdb->mlx, mdb->mlx.win, mdb->mlx.frame.img, 0, 0);
	return (0);
}
