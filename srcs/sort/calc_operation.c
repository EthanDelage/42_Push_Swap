/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:12:42 by edelage           #+#    #+#             */
/*   Updated: 2022/12/01 14:29:20 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	check_fast_place(t_list_int **stack_a, t_list_int **stack_b) 
{
	size_t			count;
	size_t			size_b;
	int				elem_top;
	int				elem_bottom;

	size_b = lstsize_int(*stack_b);
	elem_top = (*stack_a)->content;
	elem_bottom = lstlast_int(*stack_a)->content;
	count = 0;
	while (count + 1 != size_b / 2)
	{
		
	}
}

void	calculate_operation(t_list_int **stack_a)
{
	size_t	nb_arg = lstsize_int(*stack_a);
	t_list_int		*stack_b;

	stack_b = NULL;
	push_in_b(stack_a, &stack_b, nb_arg, calc_max_not_push(stack_a));
	ft_putstr_fd("b:\n", 1);
	lst_display_int(stack_b);
	lstclear_int(&stack_b);
}
