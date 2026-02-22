/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_const.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:16:05 by lbolea            #+#    #+#             */
/*   Updated: 2026/02/22 15:25:43 by lbolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_CONST_H
# define FRACTOL_CONST_H

# define BOLD "\033[1;0m"
# define ITAL "\033[3;0m"
# define NORM "\033[0;0m"

# define ERR_X "\033[1;41m ✘ ERROR \033[0m"
# define ERR_INVALID_NAME \
	"\033[1mPlease enter a correct fractal type : julia, \
mandelbrol or multibrot.\033[0m"
# define OPTIONS \
	"\n\033[1mChoose a type :\033[0m\n➤ mandelbrot \033[3manimate\033[0m\
\n➤ julia [(-)0.00...] -[(-)0.00...] \033[3manimate\033[0m \033[2m0.001643721971153 \
0.822467633298876\033[0m \n➤ multibrot \033[0m \033[3manimate\
\033[0m\n\033[2m(add 'animate' option for animated color shifting)\033[0m"

// FULLSCREEN
// H 1370
// W 2560

# define H 288
# define W 512

/// KEYS MAP

# define ESC 0xFF1B
# define ARR_L 0xFF51
# define ARR_R 0xFF53
# define ARR_UP 0xFF52
# define ARR_DOWN 0xFF54

#endif