/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:52:33 by edelage           #+#    #+#             */
/*   Updated: 2022/11/28 04:00:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

#include <stdio.h>

static void	free_for_error(t_list_int **start)
{
	lstclear_int(start);
	print_error_msg(errno);
}

t_list_int	*init_a_stack(int argc, char **argv)
{
	int			number;
	t_list_int	*start;
	t_list_int	*new_elem;

	start = NULL;
	while (argc != 1)
	{
		number = check_number(argv[argc - 1]);
		if (errno == ERANGE || errno == EINVAL)
			free_for_error(&start);
		new_elem = lstnew_int(number);
		if (new_elem == NULL)
			free_for_error(&start);
		lstadd_front_int(&start, new_elem);
		argc--;
	}
	return (start);
}
