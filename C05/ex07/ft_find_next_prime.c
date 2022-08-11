/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:28:57 by fleduc            #+#    #+#             */
/*   Updated: 2022/02/06 15:50:09 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	while (i < nb / i)
	{
		if (nb % i == 0)
			return (0);
		++i;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb == 4)
		return (5);
	else if (nb < 2)
		return (2);
	else if (ft_is_prime(nb))
		return (nb);
	else
	{
		while (!(ft_is_prime(nb)))
			++nb;
		return (nb);
	}
}
