/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 02:51:20 by edelage           #+#    #+#             */
/*   Updated: 2022/12/03 02:51:21 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_3(t_list_int **stack_a)
{
	int	min;
	int	max;
	int	first_val;
	int	second_val;

	min = lst_min_int(*stack_a);
	max = lst_max_int(*stack_a);
	first_val = (*stack_a)->content;
	second_val = (*stack_a)->next->content;
	if (first_val == max && second_val == min)
	{
		ft_putstr_fd("ra\n", 1);
		r_one(stack_a);
	}
	else if (second_val == max && first_val != min)
	{
		ft_putstr_fd("rra\n", 1);
		rr_one(stack_a);
	}
	else if ((first_val == min && second_val == max)
		|| (second_val == min && first_val != max)
		|| (first_val == max && second_val != min))
	{
		ft_putstr_fd("sa\n", 1);
		s_one(stack_a);
		sort_3(stack_a);
	}
}
