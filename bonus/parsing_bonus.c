/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:39:55 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/22 19:46:58 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

static int	check_limits(char *s)
{
	double	val;

	val = ft_atof(s);
	if (val > __FLT_MAX__ || val < -__FLT_MAX__)
		return (0);
	return (1);
}

int	is_number(char *s)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i] || s[i] == '.')
		return (0);
	while (s[i])
	{
		if (s[i] == '.')
		{
			dot++;
			if (dot > 1)
				return (0);
		}
		else if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (check_limits(s));
}

void	handle_error(void)
{
	ft_printf("%s %s\n", ERR_X, ERR_INVALID_NAME);
	ft_printf("%s\n", OPTIONS);
	exit(EXIT_FAILURE);
}

static void	is_animated(int argc, char **argv, int nb, t_dataset *graphic)
{
	if (argc == nb)
	{
		if (!ft_strncmp(argv[nb - 1], "animate", 8))
			graphic->anim = ANIMATED;
	}
	else if (argc == nb - 1)
		graphic->anim = STATIC;
	else
		handle_error();
}

void	parsing(int argc, char **argv, t_dataset *graphic)
{
	graphic->anim = STATIC;
	if (argc >= 4 && !ft_strncmp(argv[1], "julia", 6))
	{
		is_animated(argc, argv, 5, graphic);
		if (is_number(argv[2]) && is_number(argv[3]))
		{
			graphic->fract.type = JULIA;
			graphic->fract.j.reel = ft_atof(argv[2]);
			graphic->fract.j.img = ft_atof(argv[3]);
		}
		else
			handle_error();
	}
	else if (argc >= 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
	{
		graphic->fract.type = MANDELBROT;
		is_animated(argc, argv, 3, graphic);
	}
	else if (argc >= 2 && !ft_strncmp(argv[1], "multibrot", 10))
	{
		graphic->fract.type = MULTIBROT;
		is_animated(argc, argv, 3, graphic);
	}
	else
		handle_error();
}
