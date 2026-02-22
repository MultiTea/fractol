/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:48:12 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/22 19:47:00 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

static int	frame_check(t_dataset *graphic)
{
	key_handler(graphic);
	if (graphic->anim == ANIMATED || !graphic->is_rendered)
	{
		render_fract(graphic);
		graphic->is_rendered = 1;
	}
	return (0);
}

static void	loop(t_dataset graphic)
{
	mlx_hook(graphic.mlx.win, KeyPress, KeyPressMask, key_pressed, &graphic);
	mlx_hook(graphic.mlx.win, KeyRelease, KeyReleaseMask, key_released,
		&graphic);
	mlx_hook(graphic.mlx.win, ButtonPress, ButtonPressMask, mouse_handler,
		&graphic);
	mlx_hook(graphic.mlx.win, DestroyNotify, NoEventMask, &close_hook,
		&graphic);
	mlx_loop_hook(graphic.mlx.mlx, frame_check, &graphic);
	mlx_loop(graphic.mlx.mlx);
}

int	main(int argc, char **argv)
{
	t_dataset	graphic;

	fract_init(&graphic);
	parsing(argc, argv, &graphic);
	init_display(&graphic.mlx);
	if (!graphic.is_rendered)
	{
		render_fract(&graphic);
		graphic.is_rendered = 1;
	}
	loop(graphic);
	return (0);
}
