/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:48:12 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/19 01:42:59 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(/*int argc, char **argv*/ void)
{
	t_mlx_data	graphic;

	// check_param(argc, argv);
	init_display(&graphic);
	mlx_loop_hook(graphic.mlx, display_rainbow, &graphic);
	mlx_put_image_to_window(graphic.mlx, graphic.win, graphic.frame.img, 0, 0);
	mlx_key_hook(graphic.win, key_handler, &graphic);
	mlx_hook(graphic.win, DestroyNotify, NoEventMask, &close_hook, &graphic);
	mlx_loop(graphic.mlx);
	return (0);
}
