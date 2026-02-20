/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:48:12 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/20 16:50:57 by lbolea           ###   ########.fr       */
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
	init_display(&graphic.mlx);
	render_fract(&graphic);
	mlx_put_image_to_window(graphic.mlx.mlx, graphic.mlx.win,
		graphic.mlx.frame.img, 0, 0);
	mlx_hook(graphic.mlx.win, KeyPress, KeyPressMask, key_pressed, &graphic);
	mlx_hook(graphic.mlx.win, KeyRelease, KeyReleaseMask, key_released,
		&graphic);
	mlx_hook(graphic.mlx.win, ButtonPress, ButtonPressMask, mouse_handler,
		&graphic);
	mlx_hook(graphic.mlx.win, DestroyNotify, NoEventMask, &close_hook,
		&graphic);
	mlx_loop_hook(graphic.mlx.mlx, key_handler, &graphic);
	mlx_loop(graphic.mlx.mlx);
	return (0);
}
