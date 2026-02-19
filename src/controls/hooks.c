/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 01:21:31 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/19 01:37:41 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	close_hook(t_mlx_data *graphic)
{
	mlx_destroy_image(graphic->mlx, graphic->frame.img);
	mlx_destroy_window(graphic->mlx, graphic->win);
	mlx_destroy_display(graphic->mlx);
	free(graphic->mlx);
	exit(EXIT_SUCCESS);
}
