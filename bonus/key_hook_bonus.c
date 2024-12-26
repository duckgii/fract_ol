/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:08:28 by yeoshin           #+#    #+#             */
/*   Updated: 2024/02/21 18:29:27 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == 123)
		left_move_hook(vars);
	else if (keycode == 124)
		right_move_hook(vars);
	else if (keycode == 125)
		down_move_hook(vars);
	else if (keycode == 126)
		up_move_hook(vars);
	else if (keycode >= Q && keycode <= R)
	{
		vars->color = keycode;
		prt_pixel(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	}
	return (0);
}

void	left_move_hook(t_vars *vars)
{
	vars->scope_x -= (vars->range) * (0.1);
	prt_pixel(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}

void	right_move_hook(t_vars *vars)
{
	vars->scope_x += (vars->range) * (0.1);
	prt_pixel(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}

void	up_move_hook(t_vars *vars)
{	
	vars->scope_y += (vars->range) * (0.1);
	prt_pixel(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}

void	down_move_hook(t_vars *vars)
{
	vars->scope_y -= (vars->range) * (0.1);
	prt_pixel(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
