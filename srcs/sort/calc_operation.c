/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:12:42 by edelage           #+#    #+#             */
/*   Updated: 2022/12/01 19:39:21 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

void	sort_in_b(t_list_int **stack_a, t_list_int **stack_b, size_t nb_arg)
{
	int	smallest;
	int	biggest;

	smallest = nb_arg / 2 - 1;
	biggest = nb_arg / 2;
	while (lstsize_int(*stack_a) > 1)
	{
		if ((*stack_a)->content == smallest || (*stack_a)-> content == biggest)
		{
			ft_putstr_fd("pa\n", 1);
			p_one(stack_a, stack_b);
			if ((*stack_b)->content == smallest && lstsize_int(*stack_b) > 1)
			{
				smallest--;
				ft_putstr_fd("rb\n", 1);
				r_one(stack_b);
			}
			else if ((*stack_b)->content == smallest)
				smallest--;
			else
				biggest++;
		}
		ft_putstr_fd("ra\n", 1);
		r_one(stack_a);
	}
	ft_putstr_fd("pa\n", 1);
	p_one(stack_a, stack_b);
	if ((*stack_b)->content == smallest)
	{
		ft_putstr_fd("rb\n", 1);
		r_one(stack_b);
	}
}

void	calculate_operation(t_list_int **stack_a)
{
	const size_t	nb_arg = lstsize_int(*stack_a);
	t_list_int		*stack_b;

	stack_b = NULL;
	sort_in_b(stack_a, &stack_b, nb_arg);
	while (stack_b)
	{
		ft_putstr_fd("pb\n", 1);
		p_one(&stack_b, stack_a);
	}
	lstclear_int(&stack_b);
}
