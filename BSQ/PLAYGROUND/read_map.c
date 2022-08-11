/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:27:07 by fleduc            #+#    #+#             */
/*   Updated: 2022/02/10 12:48:15 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/uio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int	map_size(char *argv)
{
	int	fd;
	int	size;
	char	buff;

	size = 0;
	fd = open(argv, O_RDONLY);
	while (read(fd, &buff, 1))
		++size;
	close(fd);
	return (size);
}

int	nb_lines(char *argv)
{
	int		fd;
	int		i;
	int		j;
	int		lines;
	char	*buff;

	lines = 0;
	fd = open(argv, O_RDONLY);
	buff = malloc(20 * sizeof(char));
	i = 0;
	j = 0;
	while (read(fd, &buff[i], 1))
	{
		if (buff[i] == '\n')
			break ;
		++i;
	}
	buff[i] = '\0';
	i -= 3;
	while (j < i && (buff[j] >= '0' && buff[j] <= '9'))
	{
		lines = lines * 10 + (buff[j] - '0');
		++j;
	}
	free(buff);
	close(fd);
	return (lines);
}

int	nb_columns(char *argv, int map_size)
{
	int		fd;
	int		columns;
	int		temp;
	char	*buff;

	columns = 0;
	temp = 0;
	buff = malloc(map_size * sizeof(char));
	fd = open(argv, O_RDONLY);
	read(fd, buff, map_size);
	while (buff[temp] != '\n')
		++temp;
	while (buff[++temp] != '\n')
		++columns;
	free(buff);
	close(fd);
	return (columns);
}

char	*read_map(char *argv, int lines, int columns)
{
	int		fd;
	char 	*map;
	char	*buff;
	int		i;

	fd = open(argv, O_RDONLY);
	buff = malloc(20 * sizeof(char));
	i = 0;
	while (read(fd, &buff[i], 1))
	{
		if (buff[i] == '\n')
			break ;
		++i;
	}
	map = (char *)malloc((lines * (columns + 1)) * sizeof(char));
	read(fd, map, lines * (columns + 1));
	close(fd);
	free(buff);
	return (map);
}

int	**matrix(char *map, int lines, int columns)
{
	int	**squares_map;
	int	i;
	int	j;
	int	k;

	i = 0;
	squares_map = (int **)malloc((lines + 1) * sizeof(int *));
	while (i <= lines)
	{
		squares_map[i] = (int *)malloc(columns * sizeof(int));
		++i;
	}
	i = 0;
	j = 0;
	k = 0;
	while (map[i] != '\0')
	{
		if (map[i] != '\n')
		{
			if (map[i] == '.')
			{
				squares_map[j][k] = 1;
				++k;
			}
			else if (map[i] == 'o')
			{
				squares_map[j][k] = 0;
				++k;
			}
		}
		else
		{
			k = 0;
			++j;
		}
		++i;
	}
	return (squares_map);
}

int	min_value(int a, int b, int c)
{
	int	min;

	if (a <= b && a<= c)
		min = a;
	else if (b <= a && b <= c)
		min = b;
	else
		min = c;
	return (min);
}

int	**find_squares(int **map_int, int lines, int columns)
{
	int	i;
	int	j;
	int	k;
	int	max;

	i = 1;
	j = 1;
	k = -1;
	max = 0;
	while (i < lines)
	{
		j = 1;
		while (j < columns)
		{
			if (map_int[i][j] != 0)
			{
				map_int[i][j] = map_int[i][j] + min_value(map_int[i][j - 1], map_int[i - 1][j], map_int[i - 1][j - 1]);
			}
			++j;
		}
		++i;
	}
	return (map_int);
}

void	print_map(int **square, int lines, int columns)
{
	int	max;
	int	i;
	int	j;
	int	pos[2];

	max = 0;
	pos[0] = 0;
	pos[1] = 0;
	i = 0;
	j = 0;
	while (i < lines)
	{
		j = 0;
		while (j < columns)
		{
			if (square[i][j] > max)
			{
				max = square[i][j];
				pos[0] = i;
				pos[1] = j;
			}
			++j;
		}
		++i;
	}
	i = 0;
	while (i < lines)
	{
		j = 0;
		while (j < columns)
		{
			if ((j >= (pos[1] - max + 1) && j <= pos[1]) && (i >= (pos[0] - max + 1) && i <= pos[0]))
			{
				write(1, "X", 1);
			}
			else if (square[i][j] > 0)
			{
				write(1, ".", 1);
			}
			else if (square[i][j] == 0)
			{
				write(1, "o", 1);
			}
			++j;
		}
		write(1, "\n", 1);
		++i;
	}
}

int	main(int argc, char **argv)
{
	(void)argc;

	print_map(find_squares(matrix(read_map(argv[1], nb_lines(argv[1]), nb_columns(argv[1], map_size(argv[1]))), nb_lines(argv[1]), nb_columns(argv[1], map_size(argv[1]))), nb_lines(argv[1]), nb_columns(argv[1], map_size(argv[1]))), nb_lines(argv[1]), nb_columns(argv[1], map_size(argv[1])));
}
