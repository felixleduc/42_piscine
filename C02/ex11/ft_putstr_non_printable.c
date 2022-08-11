/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:28:10 by fleduc            #+#    #+#             */
/*   Updated: 2022/01/31 10:34:12 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_non_printable(int ascii_value)
{
	int	first_digit;
	int	second_digit;

	ft_putchar('\\');
	first_digit = ascii_value / 16;
	ft_putchar(first_digit + '0');
	second_digit = ascii_value % 16;
	if (second_digit >= 10)
		ft_putchar(second_digit + 87);
	else
		ft_putchar(second_digit + '0');
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] <= 31)
		{
			ft_putchar_non_printable(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
