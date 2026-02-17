/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:31:04 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/17 18:30:20 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	key_handler(int keycode, t_data *img)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(img->mlx, img->img);
		mlx_destroy_window(img->mlx, img->win);
		mlx_destroy_display(img->mlx);
		free(img->mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
