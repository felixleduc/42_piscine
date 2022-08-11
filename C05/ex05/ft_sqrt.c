/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:05:09 by fleduc            #+#    #+#             */
/*   Updated: 2022/02/07 17:52:00 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb > 0)
	{
		while ((i * i) <= nb)
		{
			if (nb == (i * i))
				return (i);
			if (i >= 46341)
				return (0);
			++i;
		}
	}
	return (0);
}