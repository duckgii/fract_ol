/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:37:19 by yeoshin           #+#    #+#             */
/*   Updated: 2024/02/13 14:04:09 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	cal_mandelbrot(double a, double b)
{
	int		count;
	double	pre_za;
	double	za;
	double	pre_zb;
	double	zb;

	pre_za = a;
	pre_zb = b;
	count = 500;
	while (count-- > 0)
	{
		za = pre_za * pre_za - pre_zb * pre_zb + a;
		zb = 2 * pre_za * pre_zb + b;
		if (za * za + zb * zb > 4)
			return (count);
		pre_za = za;
		pre_zb = zb;
	}
	return (0);
}

int	cal_julia(double x, double y, double a, double b)
{
	int		count;
	double	pre_za;
	double	za;
	double	pre_zb;
	double	zb;

	pre_za = a;
	pre_zb = b;
	count = 500;
	while (count-- > 0)
	{
		za = pre_za * pre_za - pre_zb * pre_zb + x;
		zb = 2 * pre_za * pre_zb + y;
		if (za * za + zb * zb >= 4)
			return (count);
		pre_za = za;
		pre_zb = zb;
	}
	return (0);
}
