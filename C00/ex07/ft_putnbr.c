/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:26:41 by fleduc            #+#    #+#             */
/*   Updated: 2022/01/25 09:11:15 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

int		nb_length(int number);
char	char_convert(int number, int pos);

void	ft_putnbr(int nb)
{
	int		length;
	char	character;

	if (nb < 0)
	{
		nb = 0 - nb;
		write(1, "-", 1);
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
	}
	length = nb_length(nb);
	while (length != 0)
	{
		character = char_convert(nb, length);
		--length;
		write(1, &character, 1);
	}
}

int	nb_length(int number)
{
	int	length;

	length = 0;
	while (number > 0)
	{
		number = number / 10;
		++length;
	}
	return (length);
}

char	char_convert(int number, int pos)
{
	char	value;
	int		digit;

	value = 48;
	while (pos > 1)
	{
		number = number / 10;
		pos -= 1;
	}
	digit = number % 10;
	return (value + digit);
}
