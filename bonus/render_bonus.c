/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 12:49:08 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/22 19:47:06 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

void	fract_init(t_dataset *data)
{
	double	ratio;

	ratio = (double)W / (double)H;
	data->anim = STATIC;
	data->fract.max_i = 10000;
	data->ite = 0;
	data->max_ite = 0;
	data->fract.y.min = -1.35;
	data->fract.y.max = 1.35;
	data->fract.x.min = -1.35 * ratio;
	data->fract.x.max = 1.35 * ratio;
	data->fract.j.reel = 0;
	data->fract.j.img = 0;
	data->k.up = 0;
	data->k.down = 0;
	data->k.right = 0;
	data->k.left = 0;
	data->c.x = 0;
	data->c.y = 0;
	data->p.x = 0;
	data->p.y = 0;
	data->fract.mb.dx = 0;
	data->fract.mb.dy = 0;
	data->is_rendered = 0;
}

void	display_pixel(t_mlx_img *data, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || x < 0 || W < x || H < y)
		return ;
	dst = data->addr + (y * data->line_len + x * 4);
	*(unsigned int *)dst = color;
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

int	render_fract(t_dataset *fract)
{
	double	x2;
	double	y2;

	x2 = 0.0;
	y2 = 0.0;
	fract->p.y = -1;
	while (++fract->p.y < H)
	{
		fract->p.x = -1;
		while (++fract->p.x < W)
		{
			if (fract->fract.type == MANDELBROT)
				mandelbrot_set(fract, x2, y2);
			else if (fract->fract.type == JULIA)
				julia_set(fract);
			else if (fract->fract.type == MULTIBROT)
				multibrot_set(fract, x2, y2);
		}
	}
	fract->ite++;
	mlx_put_image_to_window(fract->mlx.mlx, fract->mlx.win,
		fract->mlx.frame.img, 0, 0);
	return (0);
}
