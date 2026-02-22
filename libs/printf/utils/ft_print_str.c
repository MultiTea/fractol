/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:34:04 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/22 15:37:29 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	ssize_t	err;

	if (!str)
	{
		err = write(1, "(null)", 6);
		return ((int)err);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
