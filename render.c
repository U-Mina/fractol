/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:32:29 by ewu               #+#    #+#             */
/*   Updated: 2024/11/16 17:08:56 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (ft_strncmp(fractol->name, "mandelbrot", 10) == 0)
				calcu_mandelbrot(x, y, fractol);
			else if (ft_strncmp(fractol->name, "julia", 5) == 0)
				calcu_julia(x, y, fractol);
			x++;
		}
		y++;
	}
	if (fractol->img == NULL || (mlx_image_to_window(fractol->mlx, fractol->img,
				0, 0) < 0))
		exit(EXIT_FAILURE);
}

/**
 * to convert pixel w.r.t. the coordinate
 * use math mapping
 * from [0 ~ width/height] to [-2 ~ 2]
 * format:
 * double scale(double unscaled_num, double new_min,
 * 		double new_max, double old_min, double old_max){
 * return ((new_max-new_min)*(unscaled_num-old_min)/(old_max-old_min)
	+ new_min);
 * set real and im part of c
 */
void	calcu_julia(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	uint32_t	color;
	int			i;

	i = 0;
	z.x = (mapping(x, -2, +2, WIDTH) * fractol->zoom) + fractol->move_x;
	z.y = (mapping(y, +2, -2, HEIGHT) * fractol->zoom) + fractol->move_y;
	c.x = fractol->j_x;
	c.y = fractol->j_y;
	while (i < fractol->iter)
	{
		z = complex_ad(complex_sq(z), c);
		if (((z.x * z.x) + (z.y * z.y)) > DIVERGE_VA)
		{
			color = mapping(i, BLACK, YELLOW, fractol->iter);
			mlx_put_pixel(fractol->img, x, y, color);
			return ;
		}
		++i;
	}
	mlx_put_pixel(fractol->img, x, y, BLUE);
}

/**
 * stop condition: diverge  or reach iter_MAX
 * if diverge, color it and modify color wrt iter_times
 * //idea: z = z*2 + c, z0 = 0;
 * z0 = 0 as start pt
 * map pixel_coordinate to complex_coor
 * old_min is 0, old_max == width/height，即画布大小 0->画布边界
 * diverge condition/out scope (sqr of abs val)
 * gradient color calcu:
 * end_c(white)-start_c(black) * (iter_times/(max_iter-start_c))
 * end_c: white 255
 * start_c: black 0
 * z: complex var
 * c: complex regu
 */
void	calcu_mandelbrot(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			color;
	int			i;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = (mapping(x, -2, +2, WIDTH) * fractol->zoom) + fractol->move_x;
	c.y = (mapping(y, +2, -2, HEIGHT) * fractol->zoom) + fractol->move_y;
	while (i < fractol->iter)
	{
		z = complex_ad(complex_sq(z), c);
		if ((z.x * z.x) + (z.y * z.y) > DIVERGE_VA)
		{
			color = mapping(i, BLACK, BLUE, fractol->iter);
			mlx_put_pixel(fractol->img, x, y, color);
			return ;
		}
		++i;
	}
	mlx_put_pixel(fractol->img, x, y, BLACK);
}
