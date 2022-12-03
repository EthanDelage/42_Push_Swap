/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:07:20 by edelage           #+#    #+#             */
/*   Updated: 2022/11/29 21:45:03 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

int	return_error(int error_code)
{
	errno = error_code;
	return (-1);
}

int	ft_issign(char c)
{
	return (c == '-' || c == '+');
}

int	check_number(const char *str)
{
	int		sign;
	size_t	index;
	int		result;

	result = 0;
	index = 0;
	sign = 1;
	while (ft_isspace(str[index]))
		index++;
	if (ft_issign(str[index]))
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (ft_isdigit(str[index]))
	{
		if ((result * 10 + (sign * (str[index] - '0'))) / 10 != result)
			return (return_error(ERANGE));
		result = result * 10 + (sign * (str[index] - '0'));
		index++;
	}
	if (str[index] != '\0' || (index && (ft_issign(str[index - 1]))))
		return (return_error(EINVAL));
	return (result);
}

int	check_multi_number(const char *str)
{
	size_t	index;

	index = 0;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '+' || str[index] == '-')
		index++;
	while (ft_isdigit(str[index]))
		index++;
	if (str[index])
		return ((int) index);
	return (0);
}

int	next_number(const char *str)
{
	size_t	index;

	index = 0;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '+' || str[index] == '-')
		index++;
	while (ft_isdigit(str[index]))
		index++;
	return (index);
}
