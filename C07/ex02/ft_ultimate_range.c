/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:45 by fleduc            #+#    #+#             */
/*   Updated: 2022/02/03 15:19:53 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	off_range;
	int	*tab;

	off_range = max - min;
	tab = (int *)malloc(off_range * sizeof(int));
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		++i;
		++min;
	}
	if (min == max)
		return (off_range);
	else
		return (-1);
}
