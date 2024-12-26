/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_type_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:37:19 by yeoshin           #+#    #+#             */
/*   Updated: 2024/02/13 14:12:38 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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

int	cal_burning_ship(double a, double b)
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
		if (pre_za * pre_zb < 0)
			zb = 2 * pre_za * pre_zb * (-1) + b;
		else
			zb = 2 * pre_za * pre_zb + b;
		if (za * za + zb * zb > 4)
			return (count);
		pre_za = za;
		pre_zb = zb;
	}
	return (0);
}
