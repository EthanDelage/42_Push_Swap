/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 00:11:08 by edelage           #+#    #+#             */
/*   Updated: 2022/11/28 01:17:06 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

void	print_error_msg(int error_code)
{
	ft_putstr_fd("Error\n", 2);
	exit(error_code);
}

void	free_for_error(t_list_int **start)
{
	lstclear_int(start);
	print_error_msg(errno);
}
