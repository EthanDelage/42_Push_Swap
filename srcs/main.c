/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:57:22 by edelage           #+#    #+#             */
/*   Updated: 2022/12/01 13:43:22 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list_int	*stack_a;

	if (argc == 1)
		print_error_msg(EINVAL);
	stack_a = parse_arg(argc, argv);
	calculate_operation(&stack_a);
	ft_putstr_fd("a:\n", 1);
	lst_display_int(stack_a);
	lstclear_int(&stack_a);
	return (0);
}
