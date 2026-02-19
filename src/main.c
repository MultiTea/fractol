/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:48:12 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/19 17:56:34 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_dataset	graphic;

	fract_init(&graphic);
	if (argc == 2 && !ft_strncmp(argv[1], "julia", 6))
		graphic.fract.type = JULIA;
	else if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
		graphic.fract.type = MANDELBROT;
	else
		return (ft_printf("Error"));
	// check_param(argc, argv);
	init_display(&graphic.mlx);
	mlx_loop_hook(graphic.mlx.mlx, render_fract, &graphic);
	mlx_put_image_to_window(graphic.mlx.mlx, graphic.mlx.win,
		graphic.mlx.frame.img, 0, 0);
	mlx_key_hook(graphic.mlx.win, key_handler, &graphic);
	mlx_hook(graphic.mlx.win, DestroyNotify, NoEventMask, &close_hook,
		&graphic);
	mlx_loop(graphic.mlx.mlx);
	return (0);
}
