/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_type.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 21:43:15 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/22 18:50:54 by lbolea           ###   ########.fr       */
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

/// FRACTAL
/* Set management */

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA,
	MULTIBROT,
}					t_fractal_type;

typedef struct s_mandel
{
	double			old_x;
	double			old_y;
	double			dx;
	double			dy;
	int				period;
}					t_mandel;

typedef struct s_julia
{
	double			reel;
	double			img;
}					t_julia;

/* Suite operations */

typedef struct s_complex
{
	double			x;
	double			y;
}					t_complex;

typedef struct s_min_max
{
	double			min;
	double			max;
}					t_min_max;

/* Display manegement */

typedef struct s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef enum e_color
{
	STATIC,
	ANIMATED,
}					t_color;

/// MOTHER OF FRACTAL

typedef struct s_fract
{
	t_fractal_type	type;
	int				i;
	int				max_i;
	t_mandel		mb;
	t_min_max		x;
	t_min_max		y;
	t_julia			j;

}					t_fract;

// MOTHERSHIP

typedef struct s_dataset
{
	t_mlx_data		mlx;
	t_fract			fract;
	t_keys			k;
	t_complex		z;
	t_complex		c;
	t_pos			p;
	t_color			anim;
	int				ite;
	int				max_ite;
	int				is_rendered;
}					t_dataset;

#endif