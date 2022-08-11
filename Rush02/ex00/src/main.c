/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulang <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:26:33 by fboulang          #+#    #+#             */
/*   Updated: 2022/02/06 15:39:45 by fboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "fct.h"

int	main(int argc, char *argv[])
{
	int						i;
	char					*d;
	unsigned long long int	*store;
	int						j;
	char					**Dictionnary;
	unsigned long long int	argvatoi;
	
	d = malloc (500 * sizeof(char));
	store = malloc (200 * sizeof(unsigned long long int));
	Dictionnary = malloc (200 * sizeof(char *));
	d = ReadDict();
	i = 0;
	j = 0;
	while (d[i] != '\0')
	{
		store[j] = ft_atoi(&d[i]);
		while (d[i] != '\n')
		{
			i++;
		}
		i++;
		j++;
	}
	j = 0;
	if (argc == 2)
	{
		argvatoi = ft_atoi(argv[1]);
		if (argvatoi < 100)
		{
			argvatoi = (ft_atoi(argv[1]) / 10 + 48);
			write (1, &argvatoi, 2);
			write (1, "\n", 1);
			argvatoi = (ft_atoi(argv[1]) % 10 + 48);
			write (1, &argvatoi, 1);
		}
	}
}
