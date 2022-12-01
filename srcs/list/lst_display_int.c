/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_display_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 01:08:32 by edelage           #+#    #+#             */
/*   Updated: 2022/11/28 03:55:13 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lst_int.h"

void	lst_display_int(t_list_int *start)
{
	while (start)
	{
		ft_putnbr_fd(start->content, 1);
		ft_putchar_fd('\n', 1);
		start = start->next;
	}
}

void	display_stack(t_list_int *stack_a, t_list_int *stack_b)
{
	ft_putstr_fd("a:\n", 1);
	lst_display_int(stack_a);
	ft_putstr_fd("b:\n", 1);
	lst_display_int(stack_b);
}