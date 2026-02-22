/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:28:27 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/22 19:47:04 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

int	hsv_to_rgb(double h, double s, double v)
{
	int		c;
	double	f;
	int		q;
	int		t;

	(void)s;
	(void)v;
	c = (int)(h / 60.0) % 6;
	f = (h / 60.0) - c;
	q = (1.0 - f) * 255.0;
	t = f * 255.0;
	if (c == 0)
		return ((225 << 16) | (t << 8) | 0);
	if (c == 1)
		return ((q << 16) | (255 << 8) | 0);
	if (c == 2)
		return ((0 << 16) | (255 << 8) | t);
	if (c == 3)
		return ((0 << 16) | (q << 8) | 255);
	if (c == 4)
		return ((t << 16) | (0 << 8) | 255);
	return ((225 << 16) | (0 << 8) | q);
}

int	hsv_animate(t_dataset *fract, int n)
{
	double	hue;
	double	factor;

	if (n == fract->max_ite)
		return (0x000000);
	factor = 15.0;
	hue = ((double)(n * n) / factor) + (double)fract->ite;
	return (hsv_to_rgb(hue, 1.0, 1.0));
}
