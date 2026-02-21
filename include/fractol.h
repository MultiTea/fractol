/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:48:27 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/21 23:20:36 by lbolea           ###   ########.fr       */
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
# include <math.h>
# include <string.h>
# include <unistd.h>

/// PROTOTYPES

t_mlx_data	init_display(t_mlx_data *graphic);
int			hsv_to_rgb(double h, double s, double v);
int			hsv_animate(t_dataset *fract, int n);
int			key_handler(t_dataset *graphic);
int			close_hook(t_dataset *graphic);
void		display_pixel(t_mlx_img *data, int x, int y, int color);
void		fract_init(t_dataset *data);
void		parsing(int argc, char **argv, t_dataset *graphic);
void		display_fract(t_dataset *fract, int i);
int			render_fract(t_dataset *fract);
void		julia_set(t_dataset *julia);
void		mandelbrot_set(t_dataset *mdb, double x2, double y2);
void		multibrot_set(t_dataset *mdb, double x2, double y2);
int			mouse_handler(int button, int x, int y, t_dataset *graphic);
int			key_pressed(int keycode, t_dataset *graphic);
int			key_released(int keycode, t_dataset *graphic);

#endif