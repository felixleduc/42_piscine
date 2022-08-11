/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 11:36:46 by fleduc            #+#    #+#             */
/*   Updated: 2022/01/23 12:50:05 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putchar(char c);

void	x_y_decrement(int *x, int *y)
{
	--*x;
	--*y;
}

void	first_line_loop(int *x)
{
	if (*x != 1)
	{
		ft_putchar('*');
	}
	else
	{
		ft_putchar('\\');
	}
	--*x;
}

void	downward_lines_loop(int *x)
{
	ft_putchar('\n');
	ft_putchar('*');
	while (*x != 1)
	{
		ft_putchar(' ');
		--*x;
	}
	ft_putchar('*');
}

void	last_line_loop(int *x)
{
	ft_putchar('\n');
	ft_putchar('\\');
	while (*x > 0)
	{
		if (*x != 1)
		{
			ft_putchar('*');
		}
		else
		{
			ft_putchar('/');
		}
		--*x;
	}
}

void	rush(int x, int y)
{
	int	x_reset;

	if (!((x == 0 || y == 0) || (x == 0 && y == 0)))
		ft_putchar('/');
	x_y_decrement(&x, &y);
	x_reset = x;
	while (x > 0)
	{
		first_line_loop(&x);
	}
	x = x_reset;
	while (y > 0)
	{
		if (y != 1)
		{
			downward_lines_loop(&x);
			x = x_reset;
		}
		else
		{
			last_line_loop(&x);
		}
		--y;
	}
	ft_putchar('\n');
}
