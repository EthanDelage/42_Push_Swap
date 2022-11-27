/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:07:20 by edelage           #+#    #+#             */
/*   Updated: 2022/11/27 13:22:32 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

int	check_number(const char *str)
{
	int		result;
	size_t	index;
	int 	sign;

	result = 0;
	index = 0;
	sign = 1;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++
	}
	while (ft_isdigit(str[index]))
	{
		if ((result * 10 + (sign * str[index] - '0')) / 10 != result)
		{
			ft_putstr_fd(ERROR_MSG, 2);
			exit(ERANGE);
		}
		result
	}
	return (result);
}
