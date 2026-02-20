/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:48:12 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/20 20:40:37 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	loop(t_dataset graphic)
{
	mlx_hook(graphic.mlx.win, KeyPress, KeyPressMask, key_pressed, &graphic);
	mlx_hook(graphic.mlx.win, KeyRelease, KeyReleaseMask, key_released,
		&graphic);
	mlx_hook(graphic.mlx.win, ButtonPress, ButtonPressMask, mouse_handler,
		&graphic);
	mlx_hook(graphic.mlx.win, DestroyNotify, NoEventMask, &close_hook,
		&graphic);
	mlx_loop_hook(graphic.mlx.mlx, key_handler, &graphic);
	mlx_loop(graphic.mlx.mlx);
}

int	main(int argc, char **argv)
{
	t_dataset	graphic;

	fract_init(&graphic);
	if (argc == 2 && !ft_strncmp(argv[1], "julia", 6))
		graphic.fract.type = JULIA;
	else if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
		graphic.fract.type = MANDELBROT;
	else if (argc == 2 && !ft_strncmp(argv[1], "multibrot", 10))
		graphic.fract.type = MULTIBROT;
	else
		return (ft_printf("Error"));
	init_display(&graphic.mlx);
	render_fract(&graphic);
	loop(graphic);
	return (0);
}
