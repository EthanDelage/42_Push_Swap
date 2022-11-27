/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:57:22 by edelage           #+#    #+#             */
/*   Updated: 2022/11/27 13:03:26 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

void	error_arg(void)
{
	ft_putstr_fd(ERROR_MSG, 2);
	exit(EINVAL);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		error_arg();

	return (0);
}
