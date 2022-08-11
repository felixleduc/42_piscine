/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:25:37 by fleduc            #+#    #+#             */
/*   Updated: 2022/02/03 14:01:36 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	base_length(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	if (i % 2 == 0 && i <= 16)
		return (i);
	return (0);
}

int	valid_base(char *base)
{
	int	i;
	int	j;

	i = -1;
	if (!(base[0]) || !(base[1]))
		return (0);
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
	}
	i = -1;
	while (base[++i])
	{
		j = i;
		while (base[++j])
			if (base[j] == base[i])
				return (0);
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	n;

	n = base_length(base);
	if (valid_base(base) && n)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		if (nbr >= n)
		{
			ft_putnbr_base(nbr / n, base);
			ft_putnbr_base(nbr % n, base);
		}
		else
			ft_putchar(base[nbr]);
	}
}
