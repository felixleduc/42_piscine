/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:48:24 by fleduc            #+#    #+#             */
/*   Updated: 2022/02/08 14:05:46 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		n;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i])
	{
		n = 0;
		while (str[i + n] == to_find[n])
		{
			++n;
			if (!to_find[n])
				return (str + i);
		}
		++i;
	}
	return (0);
}

#include<stdio.h>
int	main()
{
	printf("%s", ft_strstr("", "str"));
}
