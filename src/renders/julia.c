/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 12:36:48 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/19 18:39:34 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	julia_set(t_dataset *julia, int x, int y)
{
	int			i;
	double		tmp;
	t_complex	z;
	t_complex	c;

	i = 0;
	z.x = map((double)x, julia->fract.min_x, julia->fract.max_x, (double)W);
	z.y = map((double)y, julia->fract.max_y, julia->fract.min_y, (double)H);
	c.x = julia->fract.julia_x;
	c.y = julia->fract.julia_y;
	while (i < julia->fract.max_i)
	{
		if ((z.x * z.x + z.y * z.y) > 4)
			break ;
		tmp = (z.x * z.x) - (z.y * z.y);
		z.y = 2 * z.x * z.y + c.y;
		z.x = tmp + c.x;
		i++;
	}
	display_fract(julia, z, x, y, i);
}
