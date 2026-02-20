/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:25:59 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/20 14:12:35 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	key_pressed(int keycode, t_dataset *graphic)
{
	if (keycode == ESC)
	{
		close_hook(graphic);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == ARR_UP)
		graphic->k.up = 1;
	else if (keycode == ARR_DOWN)
		graphic->k.down = 1;
	else if (keycode == ARR_R)
		graphic->k.right = 1;
	else if (keycode == ARR_L)
		graphic->k.left = 1;
	return (0);
}

int	key_released(int keycode, t_dataset *graphic)
{
	if (keycode == ARR_UP)
		graphic->k.up = 0;
	else if (keycode == ARR_DOWN)
		graphic->k.down = 0;
	else if (keycode == ARR_R)
		graphic->k.right = 0;
	else if (keycode == ARR_L)
		graphic->k.left = 0;
	return (0);
}
