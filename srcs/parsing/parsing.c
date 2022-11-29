/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:52:33 by edelage           #+#    #+#             */
/*   Updated: 2022/11/29 19:41:22 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

#include <stdio.h>

static void	free_for_error(t_list_int **start)
{
	lstclear_int(start);
	print_error_msg(errno);
}

static int	check_one(t_list_int *start, int to_comp)
{
	while (start)
	{
		if (start->content == to_comp)
			return (1);
		start = start->next;
	}
	return (0);
}

static int	check_dup(t_list_int *start)
{
	if (!start)
		return (-1);
	while (start->next)
	{
		if (check_one(start->next, start->content))
			return (1);
		start = start->next;
	}
	return (0);
}

static t_list_int	*init_a_stack(int argc, char **argv)
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

t_list_int	*parse_arg(int argc, char **argv)
{
	t_list_int	*init_lst_int;

	init_lst_int = NULL;
	init_lst_int = init_a_stack(argc, argv);
	if (check_dup(init_lst_int) != 0
			&& convert_by_index(init_lst_int) == FAILURE)
	{
		errno = EINVAL;
		free_for_error(&init_lst_int);
	}
	return (init_lst_int);
}
