/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:14:22 by yeoshin           #+#    #+#             */
/*   Updated: 2024/02/25 14:21:05 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	graphic_init(t_vars *vars, int ac, char **av)
{
	vars->arg = av;
	vars->arc = ac;
	vars->scope_x = 0;
	vars->scope_y = 0;
	vars->range = (double)4;
	vars->color = 1;
}

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	change_color(t_vars *vars, int i, int j, int num)
{
	if (vars->color == 1)
		num = (num % 256) << 4;
	else if (vars->color == Q)
		num = (num % 256) << 5;
	else if (vars->color == W)
		num = (num % 256) << 7;
	else if (vars->color == E)
		num = (num % 256) << 10;
	else if (vars->color == R)
		num = (num % 256) << 16;
	my_mlx_pixel_put(vars, i, j, num);
}

int	exit_hook(void)
{
	exit(0);
}
