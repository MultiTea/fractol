/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:41:17 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/19 11:08:59 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	display_pixel(t_mlx_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	display_rainbow(t_mlx_data *graphic)
{
	static int	i = 0;
	int			x;
	int			y;
	int			color;

	x = 0;
	while (x < W)
	{
		y = 0;
		color = hsv_to_rgb(((x + (i * 12)) % W) * 360.0 / W, 1.0, 1.0);
		while (y < H)
		{
			display_pixel(&graphic->frame, x, y, color);
			y++;
		}
		x++;
	}
	i++;
	mlx_put_image_to_window(graphic->mlx, graphic->win, graphic->frame.img, 0,
		0);
	if (i == W)
		i = 0;
	return (0);
}
