/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:48:12 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/17 18:31:02 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	display_img(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	display_rectangle(t_data *img)
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
			display_img(img, x, y, color);
			y++;
		}
		x++;
	}
	i++;
	if (i == W)
		i = 0;
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;
	t_data	img;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, W, H, "KAKOU KAKOU!");
	img.mlx = mlx;
	img.win = win;
	img.img = mlx_new_image(mlx, W, H);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	mlx_loop_hook(mlx, display_rectangle, &img);
	mlx_key_hook(img.win, key_handler, &img);
	mlx_loop(mlx);
	return (0);
}
