/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:21:18 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/21 23:10:39 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <unistd.h>

static void	sign_check(const char *nptr, double *sign, unsigned int *idx)
{
	unsigned int	i;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			*sign = -1;
		i++;
	}
	*idx = i;
}

double	ft_atof(const char *nptr)
{
	unsigned int	i;
	double			nb;
	double			sign;
	double			div;

	i = 0;
	nb = 0;
	sign = 1;
	div = 1;
	sign_check(nptr, &sign, &i);
	while (nptr[i] >= '0' && nptr[i] <= '9')
		nb = nb * 10 + (nptr[i++] - '0');
	if (nptr[i] == '.')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i++] - '0');
		div *= 10;
	}
	return (nb * sign / div);
}
