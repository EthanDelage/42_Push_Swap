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

void	sort_elem(t_list_int **stack_a, t_list_int **stack_b)
{
	int	val_top_a;

	val_top_a = (*stack_a)->content;
	while ((*stack_b)->content != val_top_a - 1)
	{
		ft_putstr_fd("rb\n", 1);
		r_one(stack_b);
	}
	ft_putstr_fd("pa\n", 1);
	p_one(stack_b, stack_a);
}

void	sort_7(t_list_int **stack_a)
{
	const size_t	nb_elem = lstsize_int(*stack_a);
	t_list_int		*stack_b;

	stack_b = NULL;
	while (lstsize_int(*stack_a) != 3)
	{
		if ((size_t)(*stack_a)->content != nb_elem - 1
			&& (size_t)(*stack_a)->content != nb_elem - 2
			&& (size_t)(*stack_a)->content != nb_elem - 3)
		{
			ft_putstr_fd("pb\n", 1);
			p_one(stack_a, &stack_b);
		}
		else
		{
			ft_putstr_fd("ra\n", 1);
			r_one(stack_a);
		}
	}
	sort_3(stack_a);
	while (stack_b)
		sort_elem(stack_a, &stack_b);
}
