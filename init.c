/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:06:19 by ewu               #+#    #+#             */
/*   Updated: 2024/11/16 17:07:02 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// IDEA init mlx, color scheme, data scheme (iter times, size etc)

void	ft_error_exit(t_fractol *fractol)
{
	ft_printf("Errors in initialization");
	if (fractol->img != NULL)
		mlx_delete_image(fractol->mlx, fractol->img);
	if (fractol->mlx != NULL)
		mlx_terminate(fractol->mlx);
	if (fractol)
		fractol = NULL;
	exit(EXIT_FAILURE);
}

/**
 * if (fractol->img_buffer != NULL) //todo necessary?
 * mlx_delete_image(fractol->mlx, fractol->img_buffer);
 */
void	ft_exit(t_fractol *fractol)
{
	mlx_close_window(fractol->mlx);
	if (fractol->img != NULL)
		mlx_delete_image(fractol->mlx, fractol->img);
	if (fractol->mlx != NULL)
		mlx_terminate(fractol->mlx);
	if (fractol)
		fractol = NULL;
	exit(EXIT_SUCCESS);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->iter = 200;
	fractol->zoom = 1.0;
	fractol->move_x = 0.0;
	fractol->move_y = 0.0;
	fractol->mlx = mlx_init(WIDTH, HEIGHT, fractol->name, true);
	if (fractol->mlx == NULL)
		ft_error_exit(fractol);
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (fractol->img == NULL || (mlx_image_to_window(fractol->mlx, fractol->img,
				0, 0) < 0))
		ft_error_exit(fractol);
}

/**
 * mlx_put_pixel(fractol->img, 0, 0, 0xFF0000FF);
 * after img being dispalyed, still can modity
 * register HOOK and pass mlx as optional para
 * mlx_loop(fractol->mlx);
 * mlx_terminate(fractol->mlx);
 * exit(EXIT_SUCCESS);
 */
void	event_init(void *param)
{
	t_fractol	*fractol;

	fractol = param;
	mlx_key_hook(fractol->mlx, &frac_keyhook, fractol);
	mlx_scroll_hook(fractol->mlx, &frac_scrollhook, fractol);
	mlx_close_hook(fractol->mlx, &frac_closehook, fractol);
}
