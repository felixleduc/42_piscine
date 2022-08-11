/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:05:56 by fleduc            #+#    #+#             */
/*   Updated: 2022/02/08 17:42:49 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	range = NULL;
	if (min >= max)
		return (range);
	range = (int *)malloc((max - min) * sizeof(int));
	i = 0;
	while (min < max)
	{
		range[i] = min;
		++min;
		++i;
	}
	return (range);
}
