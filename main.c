/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:01:39 by ewu               #+#    #+#             */
/*   Updated: 2024/11/16 17:07:18 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * else {printf("ass\n");
 * return (1);}
 * to start the program
 * mlx_loop: loop_hook init and check
 */
int	main(int ac, char **av)
{
	t_fractol	fractol;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) || (ac == 4
			&& !ft_strncmp(av[1], "julia", 5)))
	{
		fractol.name = av[1];
		if (ac == 4)
		{
			fractol.j_x = ft_todouble(av[2]);
			fractol.j_y = ft_todouble(av[3]);
		}
		fractol_init(&fractol);
		fractol_render(&fractol);
		mlx_loop_hook(fractol.mlx, &event_init, &fractol);
		mlx_loop(fractol.mlx);
		ft_exit(&fractol);
	}
	else
	{
		ft_printf("\t\t\t\033[1;31mInvalid Input!\033[0m\n");
		ft_printf("\t\t\t\033[31mPlease use following format:\033[0m\n");
		ft_printf("\t\t\t\033[32mmandelbrot\033[0m\n");
		ft_printf("\t\t\t\033[32mjulia, number1, number2\033[0m\n");
		return (1);
	}
}
