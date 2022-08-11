/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:35:13 by fleduc            #+#    #+#             */
/*   Updated: 2022/02/07 18:37:43 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	switch_max_to_min(int *actual, int *compare, int *stocked_v)
{
	if (*actual > *compare)
	{
		*stocked_v = *actual;
		*actual = *compare;
		*compare = *stocked_v;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	*actual;
	int	*compare;
	int	stocked_v;
	int	*end;

	actual = tab;
	compare = tab;
	end = (tab + size - 1);
	stocked_v = *tab;
	while (actual <= end)
	{
		if (compare <= end)
		{
			switch_max_to_min(actual, compare, &stocked_v);
			++compare;
		}
		else
		{
			++actual;
			compare = actual;
		}
	}
}
