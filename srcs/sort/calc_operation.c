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

void	right_shift(t_list_int *stack_a)
{
	while (stack_a)
	{
		stack_a->content >>= 1;
		stack_a = stack_a->next;
	}
}

void	push_all_a(t_list_int **stack_a, t_list_int **stack_b)
{
	while (*stack_b)
	{
		ft_putstr_fd("pa\n", 1);
		p_one(stack_b, stack_a);
	}
}

void	sort_index(t_list_int **stack_a, t_list_int **stack_b
	, size_t total_size)
{
	size_t	count;

	count = 0;
	while (count < total_size)
	{
		if (((*stack_a)->content & 0b1) == 0)
		{
			ft_putstr_fd("pb\n", 1);
			p_one(stack_a, stack_b);
		}
		else
		{
			ft_putstr_fd("ra\n", 1);
			r_one(stack_a);
		}
		count++;
	}
	push_all_a(stack_a, stack_b);
}

int	lst_issort(t_list_int *stack_a)
{
	while (stack_a)
	{
		if (stack_a->content != 0)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	calculate_operation(t_list_int **stack_a)
{
	const size_t	nb_arg = lstsize_int(*stack_a);
	t_list_int		*stack_b;

	stack_b = NULL;
	while (!lst_issort(*stack_a))
	{
		sort_index(stack_a, &stack_b, nb_arg);
		right_shift(*stack_a);
	}
}
