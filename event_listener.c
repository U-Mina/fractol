/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:52:03 by ewu               #+#    #+#             */
/*   Updated: 2024/11/16 17:06:18 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	frac_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fractol	*fractol;

	fractol = param;
	if ((keydata.key == MLX_KEY_ESCAPE) && keydata.action == MLX_PRESS)
		mlx_close_window(fractol->mlx);
	if ((keydata.key == MLX_KEY_MINUS) && keydata.action == MLX_PRESS)
		fractol->iter -= 8;
	if ((keydata.key == MLX_KEY_EQUAL) && keydata.action == MLX_PRESS)
		fractol->iter += 8;
	if ((keydata.key == MLX_KEY_UP) && keydata.action == MLX_PRESS)
		fractol->move_y -= (0.5 * fractol->zoom);
	if ((keydata.key == MLX_KEY_DOWN) && keydata.action == MLX_PRESS)
		fractol->move_y += (0.5 * fractol->zoom);
	if ((keydata.key == MLX_KEY_LEFT) && keydata.action == MLX_PRESS)
		fractol->move_x -= (0.5 * fractol->zoom);
	if ((keydata.key == MLX_KEY_RIGHT) && keydata.action == MLX_PRESS)
		fractol->move_x += (0.5 * fractol->zoom);
	fractol_render(fractol);
}

void	frac_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;

	(void)xdelta;
	fractol = param;
	if (ydelta > 0)
		fractol->zoom *= ZOOM_IN;
	else if (ydelta < 0)
		fractol->zoom *= ZOOM_OUT;
	fractol_render(fractol);
}

void	frac_closehook(void *param)
{
	t_fractol	*fractol;

	fractol = param;
	ft_exit(fractol);
}
