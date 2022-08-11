/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:52:10 by fleduc            #+#    #+#             */
/*   Updated: 2022/02/05 17:41:22 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	count_minuses(char *str)
{
	int	i;
	int	minus_count;

	i = -1;
	minus_count = 0;
	while (!(str[++i] >= '0' && str[++i] <= '9'))
	{
		if (str[i] == '-')
			++minus_count;
	}
	return (minus_count);
}

int	ft_atoi(char *str)
{	
	int	i;
	int	digit;
	int	sign;

	i = 0;
	digit = 0;
	sign = 1;
	if (!(count_minuses(str) % 2 == 0))
		sign = -1;
	while (str[i] && !(str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] != 32 && !(str[i] >= 9 && str[i] <= 13) 
				&& str[i] != '-' && str[i] != '+')
			return (0);
		++i;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		digit = digit * 10 + (str[i] - 48);
		++i;
	}
	return (digit * sign);
}
