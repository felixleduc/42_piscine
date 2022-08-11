/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:49:50 by fleduc            #+#    #+#             */
/*   Updated: 2022/01/22 18:19:30 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	while_looper(int a, int b, int c, int d);
void	mega_printer(int a, int b, int c, int d);

void	ft_print_comb2(void)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = 0;
	b = 0;
	c = 0;
	d = 0;
	while_looper(a, b, c, d);
}

void	while_looper(int a, int b, int c, int d)
{
	while (a <= 9)
	{
		while (b <= 9)
		{
			while (c <= 9)
			{
				while (d <= 9)
				{
					if ((a * 10 + b) < (c * 10 + d))
						mega_printer(a, b, c, d);
					++d;
				}
				d = 0;
				++c;
			}
			c = 0;
			++b;
		}
		b = 0;
		++a;
	}
}

void	mega_printer(int a, int b, int c, int d)
{
	a += 48;
	b += 48;
	c += 48;
	d += 48;
	if (!((a + b + c) == 144 && d == 49))
		write(1, " ", 1);
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (!((a == 57) && (b == 56)))
		write(1, ",", 1);
}
