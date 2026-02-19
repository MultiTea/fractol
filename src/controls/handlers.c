/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:31:04 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/19 01:42:20 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	key_handler(int keycode, t_mlx_data *graphic)
{
	if (keycode == ESC)
		close_hook(graphic);
	return (0);
}
