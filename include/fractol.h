/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:48:27 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/19 10:57:53 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libs/Libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/minilibx-linux/mlx_int.h"
# include "../libs/printf/include/ft_printf.h"
# include "./fractol_const.h"
# include "./fractol_type.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/// PROTOTYPES

void		check_param(int argc, char **argv);
t_mlx_data	init_display(t_mlx_data *graphic);
int			hsv_to_rgb(double h, double s, double v);
int			key_handler(int keycode, t_mlx_data *graphic);
int			display_rainbow(t_mlx_data *graphic);
int			close_hook(t_mlx_data *graphic);
void		display_pixel(t_mlx_img *data, int x, int y, int color);
int			mandelbrot_set(t_dataset *mdb, t_pixel p);

#endif