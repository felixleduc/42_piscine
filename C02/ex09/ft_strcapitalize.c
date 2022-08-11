/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:04:54 by fleduc            #+#    #+#             */
/*   Updated: 2022/02/02 14:50:41 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*all_lowercase(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] >= 'A' && string[i] <= 'Z')
		{
			string[i] += 32;
		}
		++i;
	}
	return (string);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	bool_alike;

	i = 0;
	bool_alike = 1;
	all_lowercase(str);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (bool_alike == 1)
				str[i] -= 32;
			bool_alike = 0;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			bool_alike = 0;
		else
			bool_alike = 1;
		++i;
	}
	return (str);
}
