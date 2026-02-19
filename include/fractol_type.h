/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_type.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 21:43:15 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/19 10:21:52 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_TYPE_H
# define FRACTOL_TYPE_H

typedef struct s_mlx_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}					t_mlx_img;

typedef struct s_mlx_data
{
	void			*mlx;
	void			*win;
	t_mlx_img		frame;
}					t_mlx_data;

typedef struct s_resolution
{
	int				width;
	int				height;
}					t_resolution;

typedef struct s_pixel
{
	int				x;
	int				y;
}					t_pixel;

typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct s_hsv
{
	double			h;
	double			s;
	double			v;
}					t_hsv;

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA,
}					t_fractal_type;

typedef struct s_fract
{
	t_fractal_type	type;
	int				max_i;

}					t_fract;

typedef struct s_dataset
{
	t_mlx_data		mlx;
	t_resolution	res;
	t_fract			fract;
}					t_dataset;

#endif