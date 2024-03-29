/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:29:09 by edelage           #+#    #+#             */
/*   Updated: 2022/12/14 23:06:14 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <errno.h>

static int	return_error(int error_code)
{
	errno = error_code;
	return (-1);
}

int	ft_atoi(const char *nptr)
{
	int	index;
	int	sign;
	int	result;

	index = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(nptr[index]))
		index++;
	if (ft_issign(nptr[index]))
	{
		if (nptr[index] == '-')
			sign = -1;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		if ((result * 10 + (sign * (nptr[index] - '0'))) / 10 != result)
			return (return_error(ERANGE));
		result = result * 10 + sign * (nptr[index] - '0');
		index++;
	}
	if (nptr[index] != '\0' && !ft_isspace(nptr[index]))
		return (return_error(EINVAL));
	return (result);
}
