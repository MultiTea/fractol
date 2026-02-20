/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:39:55 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/20 17:28:58 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	check_param(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc <= ARGC_MIN)
	{
		ft_printf("%s %s", ERR_SIGN, ERR_MSG_EMPTY_ARGS);
		exit(EXIT_FAILURE);
	}
	while (argv[i])
	{
		if (argc >= ARGC_MIN)
		{
			ft_printf("%s %s", ERR_SIGN, ERR_MSG_INVALID_NAME);
			exit(EXIT_FAILURE);
		}
	}
}
