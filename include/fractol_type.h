/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_type.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 21:43:15 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/20 20:39:06 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_TYPE_H
# define FRACTOL_TYPE_H

// MINILIBX
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

// HOOKS
typedef struct s_keys
{
	int				up;
	int				down;
	int				left;
	int				right;
}					t_keys;

// FRACTAL
typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA,
	MULTIBROT,
}					t_fractal_type;

typedef struct s_complex
{
	double			x;
	double			y;
}					t_complex;

typedef struct s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct s_fract
{
	t_fractal_type	type;
	double			min_x;
	double			max_x;
	double			min_y;
	double			max_y;
	double			julia_x;
	double			julia_y;
	int				max_i;
}					t_fract;

// MOTHERSHIP
typedef struct s_dataset
{
	t_mlx_data		mlx;
	t_fract			fract;
	t_keys			k;
}					t_dataset;

#endif