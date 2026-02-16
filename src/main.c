/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:48:12 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/16 19:51:07 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	key_handler(int keycode, void *param)
{
	(void)param;
	if (keycode == 0xFF1B)
		exit(0);
	return (0);
}

void	display_img(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*win;
	t_data	img;
	int		x;
	int		y;
	int		color;
	int		res;
	int		res_y;
	int		res_x;

	x = 0;
	y = 0;
	res_y = 0;
	res_x = 0;
	color = 1;
	mlx = mlx_init();
	res = mlx_get_screen_size(mlx, &res_x, &res_y);
	win = mlx_new_window(mlx, (res_x / 2), (res_y / 2), "KAKOU KAKOU!");
	img.img = mlx_new_image(mlx, res_x, res_y);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	while (x <= res_x)
	{
		y = 0;
		while (y < res_y)
		{
			display_img(&img, x, y, color);
			y++;
		}
		x++;
		color *= 99;
	}
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_key_hook(win, key_handler, NULL);
	mlx_loop(mlx);
	return (0);
}
