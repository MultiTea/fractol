/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_to_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:28:27 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/18 21:51:49 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static t_rgb	set_rgb(int r, int g, int b)
{
	t_rgb	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

static t_rgb	find_neighbouring(t_hsv hsv, int c)
{
	double	f;
	int		p;
	int		q;
	int		t;

	f = (hsv.h / 60.0) - c;
	p = (hsv.v * (1 - hsv.s) * 255);
	q = (hsv.v * (1 - f * hsv.s) * 255);
	t = (hsv.v * (1 - (1 - f) * hsv.s) * 255);
	hsv.v *= 255;
	if (c == 0)
		return (set_rgb(hsv.v, t, p));
	if (c == 1)
		return (set_rgb(q, hsv.v, p));
	if (c == 2)
		return (set_rgb(p, hsv.v, t));
	if (c == 3)
		return (set_rgb(p, q, hsv.v));
	if (c == 4)
		return (set_rgb(t, p, hsv.v));
	return (set_rgb(hsv.v, p, q));
}

int	hsv_to_rgb(double h, double s, double v)
{
	int		chroma;
	t_rgb	color;
	t_hsv	hsv;

	hsv.h = h;
	hsv.s = s;
	hsv.v = v;
	chroma = (int)(h / 60.0) % 6;
	color = find_neighbouring(hsv, chroma);
	return ((color.r << 16) | (color.g << 8) | color.b);
}
