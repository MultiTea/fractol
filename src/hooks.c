/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 01:21:31 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/21 15:56:37 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_mlx_data	init_display(t_mlx_data *graphic)
{
	graphic->mlx = mlx_init();
	graphic->win = mlx_new_window(graphic->mlx, W, H, "fract_ol");
	graphic->frame.img = mlx_new_image(graphic->mlx, W, H);
	graphic->frame.addr = mlx_get_data_addr(graphic->frame.img,
			&graphic->frame.bpp, &graphic->frame.line_len,
			&graphic->frame.endian);
	return (*graphic);
}

int	close_hook(t_dataset *graphic)
{
	mlx_destroy_image(graphic->mlx.mlx, graphic->mlx.frame.img);
	mlx_destroy_window(graphic->mlx.mlx, graphic->mlx.win);
	mlx_destroy_display(graphic->mlx.mlx);
	free(graphic->mlx.mlx);
	exit(EXIT_SUCCESS);
}
