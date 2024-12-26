/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:31:56 by yeoshin           #+#    #+#             */
/*   Updated: 2024/02/25 14:09:21 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	isbig(char *c)
{
	if (*c == '0' && *(c + 1) == '\0')
		return ;
	while (*c == '0')
		c++;
	if (((*c >= '1' && *c <= '3') && (*(c + 1) == '.' || *(c + 1) == 0)) \
	|| *c == '.')
		return ;
	else if (*c >= '1' && *c <= '9')
	{
		ft_printf("number is too big!!\n");
		exit(1);
	}
	else
	{
		ft_printf("it is not valid number!!\n");
		exit(1);
	}
}

void	check_error(char *str)
{
	int	idx;
	int	count_dot;

	count_dot = 0;
	idx = 0;
	isbig(str);
	allnum(str);
	while (str[idx] != '\0' && (ft_isdigit(str[idx]) == 1 || str[idx] == '.'))
	{
		if (str[idx] == '.')
			count_dot++;
		idx++;
	}
	if (count_dot >= 2)
	{
		ft_printf("it is not valid number!!\n");
		exit(1);
	}
}

double	atod(char *str)
{
	int		len;
	double	before_dot;
	double	after_dot;
	int		flag;

	before_dot = 0;
	after_dot = 0;
	len = 0;
	flag = 1;
	if (*str == '-')
	{
		str++;
		flag *= -1;
	}
	check_error(str);
	while (*str != '.' && *str != '\0')
	{
		before_dot = before_dot * 10 + *str - '0';
		str++;
	}
	if (*str == '.')
		str++;
	after_dot = make_after_dot(str);
	return ((before_dot + after_dot) * flag);
}

double	make_after_dot(char *str)
{
	int		len;
	double	after_dot;

	len = 0;
	after_dot = 0;
	while (*str != '\0' && len < 15)
	{
		after_dot = after_dot * 10 + *str - '0';
		str++;
		len++;
	}
	while (len-- > 0)
		after_dot *= (0.1);
	return (after_dot);
}

void	allnum(char *str)
{
	while (*str)
	{
		if ((*str >= '0' && *str <= '9') || *str == '.')
			str++;
		else
		{
			ft_printf("it is not valid number!!\n");
			exit(1);
		}
	}
}
