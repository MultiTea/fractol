/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 22:43:17 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/19 12:28:47 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

t_mlx_data	init_display(t_mlx_data *graphic)
{
	graphic->mlx = mlx_init();
	graphic->win = mlx_new_window(graphic->mlx, W, H, "KAKOU KAKOU!");
	graphic->frame.img = mlx_new_image(graphic->mlx, W, H);
	graphic->frame.addr = mlx_get_data_addr(graphic->frame.img,
			&graphic->frame.bpp, &graphic->frame.line_len,
			&graphic->frame.endian);
	return (*graphic);
}
