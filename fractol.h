/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:38:25 by ewu               #+#    #+#             */
/*   Updated: 2024/11/16 17:09:18 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <math.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/**
 * define img and winow
 */
# define WIDTH 800
# define HEIGHT 800
# define DIVERGE_VA 4.0
# define ZOOM_IN 1.5
# define ZOOM_OUT 0.8
/**
 * define COLOR
 */
# define WHITE 0xFFFFFFFF
# define BLACK 0x000000CC
# define PINKY 0xF52891CC
# define BLUE 0xBFEBFFBD
# define PUR 0xD6B6DACC
# define YELLOW 0xE1F12FCC

/**
 * x: real number part
 * y: imagery nbr part
 */
typedef struct s_complex
{
	double		x;
	double		y;
}				t_complex;
/**
 * mlx_init()
 * iter: img quality and rendering speed
 */
typedef struct s_fractol
{
	char		*name;
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			iter;
	double		zoom;
	double		move_x;
	double		move_y;
	double		j_x;
	double		j_y;
}				t_fractol;

/**
 * init and entry
 */
void			fractol_init(t_fractol *fractol);
void			ft_exit(t_fractol *fractol);
void			ft_error_exit(t_fractol *fractol);
/**
 * rendering and calculating
 */
void			fractol_render(t_fractol *fractol);
void			calcu_mandelbrot(int x, int y, t_fractol *fractol);
void			calcu_julia(int x, int y, t_fractol *fracto);
/**
 * math equation
 */
double			mapping(double pixel_num, double n_min, double n_max,
					double old_max);
t_complex		complex_sq(t_complex z);
t_complex		complex_ad(t_complex z1, t_complex z2);
double			ft_todouble(char *s);
double			ft_fraction(char **s);
/**
 * I/O listerner
 */
void			event_init(void *param);
void			frac_keyhook(mlx_key_data_t keydata, void *param);
void			frac_closehook(void *param);
void			frac_scrollhook(double xdelta, double ydelta, void *param);

#endif