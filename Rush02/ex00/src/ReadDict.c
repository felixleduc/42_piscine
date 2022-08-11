/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReadDict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulang <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:21:01 by fboulang          #+#    #+#             */
/*   Updated: 2022/02/06 12:40:47 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include"fct.h"

#define BUFF_SIZE 4096

char	*ReadDict(void)
{
	int		b;
	char	*a;

	a = (char *)malloc(BUFF_SIZE * sizeof(char));
	b = open ("numbers.dict", O_RDONLY);
	read (b, a, BUFF_SIZE);
	return (a);
}
