/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:57:33 by ewu               #+#    #+#             */
/*   Updated: 2024/11/16 17:08:10 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	mapping(double pixel_num, double n_min, double n_max, double old_max)
{
	double	res;

	res = (n_max - n_min) * (pixel_num - 0) / (old_max - 0) + n_min;
	return (res);
}

t_complex	complex_ad(t_complex z1, t_complex z2)
{
	t_complex	sum;

	sum.x = z1.x + z2.x;
	sum.y = z1.y + z2.y;
	return (sum);
}

t_complex	complex_sq(t_complex z)
{
	t_complex	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}

double	ft_todouble(char *s)
{
	long	i;
	double	f;
	int		sign;
	double	power;

	sign = 1;
	power = 1;
	i = 0;
	f = 0.0;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	while (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			sign = -sign;
	}
	while (*s != '.' && *s)
		i = (i * 10) + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s)
		f = ft_fraction(&s);
	return (sign * (i + f));
}

double	ft_fraction(char **s)
{
	double	f;
	double	n;

	n = 0.1;
	f = 0.0;
	while (**s >= '0' && **s <= '9')
	{
		f = f + (**s - '0') * n;
		n = n / 10;
		(*s)++;
	}
	return (f);
}
