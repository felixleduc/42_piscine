/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:59:44 by fleduc            #+#    #+#             */
/*   Updated: 2022/02/03 19:02:07 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>

int	str_length(int size, char *strs[4], char *sep)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	j = 0;
	i = 0;
	while (sep[i++])
		++count;
	count *= size - 1;
	while (j < size)
	{
		i = 0;
		while (strs[j][i])
		{
			++i;
			++count;
		}
		++j;
	}
	return (count);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (dest[i] != '\0')
	{
		++i;
	}
	while (src[n] != '\0')
	{
		dest[i] = src[n];
		++n;
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char *strs[4], char *sep)
{
	int		i;
	char	*chain;

	i = 0;
	chain = (char *)malloc(str_length(size, strs, sep) * sizeof(char));
	if (size == 0)
	{
		chain = NULL;
		return (chain);
	}
	while (i < size - 1)
	{
		chain = ft_strcat(chain, strs[i]);
		chain = ft_strcat(chain, sep);
		++i;
	}
	chain = ft_strcat(chain, strs[i]);
	return (chain);
}

#include<stdio.h>
int	main(void)
{
	char	*strs[4];
	char	*jointed;
	unsigned long int	i;

	strs[0] = "no";
	strs[1] = "yes";
	strs[2] = "pls";
	strs[3] = "hum";
	i = 0;
	jointed = ft_strjoin(4, strs, " don't ");
	while (jointed[i])
	{
		printf("%c", jointed[i]);
		++i;
	}
	printf("\n");
	printf("%d", str_length(4, strs, " don't "));
}
