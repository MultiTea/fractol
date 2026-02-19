/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_const.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:16:05 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/19 18:09:13 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_CONST_H
# define FRACTOL_CONST_H

# define ERR_SIGN "\033[0;41m ✘ ERROR \033[0;1m"
# define ERR_MSG_EMPTY_ARGS \
	"Please enter a fractal type and its associated\
 parameter(s).\n"
# define ERR_MSG_INVALID_NAME "Please enter a correct fractal type.\n"

# define H 1080
# define W 1920

# define ARGC_MIN 2

/// KEYS MAP

# define ESC 0xFF1B
# define ARR_L 0xFF51
# define ARR_R 0xFF53
# define ARR_UP 0xFF52
# define ARR_DOWN 0xFF54

#endif