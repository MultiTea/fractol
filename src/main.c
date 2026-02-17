/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:48:12 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/17 14:01:45 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	display_img(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	display_rectangle(t_data *img, int h, int w)
{
	int	x;
	int	y;

	x = 0;
	while (x < w)
	{
		y = 0;
		while (y < h)
		{
			display_img(img, x, y, hsv_to_rgb(((double)x / w) * 360.0, 1.0,
					1.0));
			y++;
		}
		x++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*win;
	t_data	img;
	int		display[2];

	mlx = mlx_init();
	mlx_get_screen_size(mlx, &display[0], &display[1]);
	display[0] /= 2;
	display[1] /= 2;
	win = mlx_new_window(mlx, display[0], display[1], "KAKOU KAKOU!");
	img.img = mlx_new_image(mlx, display[0], display[1]);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	display_rectangle(&img, display[0], display[1]);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_key_hook(win, key_handler, NULL);
	mlx_loop(mlx);
	return (0);
}
