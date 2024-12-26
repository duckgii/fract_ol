/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:48:49 by yeoshin           #+#    #+#             */
/*   Updated: 2024/02/21 18:32:25 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	main(int ac, char *av[])
{
	av = check_arg(ac, av);
	prtimage(ac, av);
	return (0);
}

char	**check_arg(int ac, char *av[])
{
	if (ac < 2)
	{
		ft_printf("it is not valid paramiter!!\n");
		ft_printf("valid paramiter is \"Julia num1 num2\"");
		ft_printf("or \"Mandelbrot\" or \"Burning_ship\".\n");
		exit(1);
	}
	if (ft_strncmp("Julia", av[1], 6) == 0 && ft_strlen(av[1]) == 5 && ac == 4)
		return (av);
	else if (ft_strncmp("Mandelbrot", av[1], 11) == 0 && ac == 2)
		return (av);
	else if (ft_strncmp("Burning_ship", av[1], 13) == 0 && ac == 2)
		return (av);
	else
	{
		ft_printf("it is not valid paramiter!!\n");
		ft_printf("valid paramiter is \"Julia num1 num2\"");
		ft_printf("or \"Mandelbrot\" or \"Burning_ship\".\n");
		exit(1);
	}
	return (av);
}

int	prtimage(int ac, char **av)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Fractol");
	vars.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, \
	&vars.line_length, &vars.endian);
	graphic_init(&vars, ac, av);
	prt_pixel(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.mlx);
	return (0);
}

void	prt_pixel(t_vars *vars)
{
	double	pixel_x;
	double	pixel_y;
	int		num;
	double	coordinate_x;
	double	coordinate_y;

	pixel_x = -1;
	while (++pixel_x < WIDTH)
	{
		pixel_y = -1;
		while (++pixel_y < HEIGHT)
		{
			coordinate_x = vars->scope_x - (vars->range) / 2L + \
				(vars->range / WIDTH) * pixel_x;
			coordinate_y = vars->scope_y + (vars->range) / 2L - \
				(vars->range / HEIGHT) * pixel_y;
			num = prt_fractol(vars, coordinate_x, coordinate_y);
			change_color(vars, pixel_x, pixel_y, num);
		}
	}
}

int	prt_fractol(t_vars *vars, double coordinate_x, double coordinate_y)
{
	int	num;

	if (ft_strncmp(vars->arg[1], "Mandelbrot", 11) == 0)
		num = cal_mandelbrot(coordinate_x, coordinate_y);
	else if (ft_strncmp(vars->arg[1], "Julia", 6) == 0)
		num = cal_julia(atod(vars->arg[2]), atod(vars->arg[3]), \
		coordinate_x, coordinate_y);
	else
		num = cal_burning_ship(coordinate_x, (-1) * coordinate_y);
	return (num);
}
