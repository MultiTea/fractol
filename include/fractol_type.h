/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_type.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 21:43:15 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/19 01:17:39 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_TYPE_H
# define FRACTOL_TYPE_H

typedef struct s_mlx_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_mlx_img;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
	t_mlx_img	frame;
}				t_mlx_data;

typedef struct s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct s_hsv
{
	double		h;
	double		s;
	double		v;
}				t_hsv;

#endif