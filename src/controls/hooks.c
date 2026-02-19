/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 01:21:31 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/19 17:58:05 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	close_hook(t_dataset *graphic)
{
	mlx_destroy_image(graphic->mlx.mlx, graphic->mlx.frame.img);
	mlx_destroy_window(graphic->mlx.mlx, graphic->mlx.win);
	mlx_destroy_display(graphic->mlx.mlx);
	free(graphic->mlx.mlx);
	exit(EXIT_SUCCESS);
}
