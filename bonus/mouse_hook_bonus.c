/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:47:55 by yeoshin           #+#    #+#             */
/*   Updated: 2024/02/25 14:21:39 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	mouse_hook(int mouse_key, int x, int y, t_vars *vars)
{
	if (mouse_key == 5)
		enlarge_display(vars, x, y);
	else if (mouse_key == 4)
		reduce_display(vars, x, y);
	return (0);
}

void	enlarge_display(t_vars *vars, int x, int y)
{
	vars->range *= 0.5;
	vars->scope_x += ((double)x - 500) / (1000 / vars->range);
	vars->scope_y -= ((double)y - 500) / (1000 / vars->range);
	prt_pixel(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}

void	reduce_display(t_vars *vars, int x, int y)
{
	vars->scope_x -= ((double)x - 500) / (1000 / vars->range);
	vars->scope_y += ((double)y - 500) / (1000 / vars->range);
	vars->range *= 2;
	prt_pixel(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
