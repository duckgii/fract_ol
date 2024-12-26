/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:19:46 by yeoshin           #+#    #+#             */
/*   Updated: 2024/02/25 14:33:20 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <mlx.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"

# define WIDTH 1000
# define HEIGHT 1000
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define Q 12
# define W 13
# define E 14
# define R 15

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		scope_x;
	double		scope_y;
	double		range;
	char		**arg;
	int			arc;
	int			color;
}	t_vars;

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int		prtimage(int ac, char **av);
int		exit_hook(void);
int		key_hook(int keycode, t_vars *vars);
void	prt_pixel(t_vars *vars);
int		cal_fractol(double x, double y);
void	change_color(t_vars *vars, int i, int j, int num);
char	**check_arg(int ac, char *av[]);
void	print_valid(void);
void	graphic_init(t_vars *vars, int ac, char **av);
void	left_move_hook(t_vars *vars);
void	right_move_hook(t_vars *vars);
void	up_move_hook(t_vars *vars);
void	down_move_hook(t_vars *vars);
int		mouse_hook(int mouse_key, int x, int y, t_vars *vars);
void	enlarge_display(t_vars *vars, int x, int y);
void	reduce_display(t_vars *vars, int x, int y);
int		fractol_type(t_vars *vars);
int		cal_mandelbrot(double a, double b);
int		cal_julia(double x, double y, double a, double b);
void	isbig(char *s);
void	check_error(char *str);
double	atod(char *str);
double	make_after_dot(char *str);
int		cal_burning_ship(double a, double b);
int		prt_fractol(t_vars *vars, double coordinate_x, double coordinate_y);
void	allnum(char *str);

#endif