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

size_t	count_nb_sorted(t_list_int *stack_a)
{
	size_t	count;
	int		previous_val;

	count = 0;
	previous_val = stack_a->content;
	while (stack_a)
	{
		if (previous_val <= stack_a->content)
		{
			previous_val = stack_a->content;
			count++;
		}
		stack_a = stack_a->next;
	}
	return (count);
}

int	max_sort(t_list_int *stack_a)
{
	size_t	max_sorted;
	size_t	nb_sorted;
	int		best_value;

	max_sorted = 0;
	best_value = 0;
	while (stack_a)
	{
		nb_sorted = count_nb_sorted(stack_a);
		if (nb_sorted > max_sorted)
		{
			max_sorted = nb_sorted;
			best_value = stack_a->content;
		}
		stack_a = stack_a->next;
	}
	return (best_value);
}

void	push_in_b(t_list_int **stack_a, t_list_int **stack_b)
{
	const size_t	nb_arg = lstsize_int(*stack_a);
	size_t			count;
	int				value;
	int				find_value;

	value = max_sort(*stack_a);
	count = 0;
	find_value = 0;
	printf("Max_sorted = %d", value);
	while (count < nb_arg)
	{
		if ((*stack_a)->content == value)
			find_value = 1;
		if (find_value && (*stack_a)->content >= value)
		{
			value = (*stack_a)->content;
			ft_putstr_fd("ra\n", 1);
			r_one(stack_a);
		}
		else
		{
			ft_putstr_fd("pb\n", 1);
			p_one(stack_a, stack_b);
		}
		count++;
	}
}

void	calculate_operation(t_list_int **stack_a)
{
	t_list_int		*stack_b;

	stack_b = NULL;
	push_in_b(stack_a, &stack_b);
	display_stack(*stack_a, stack_b);
	nb_move_for_place(*stack_a, stack_b, 3);
	lstclear_int(&stack_b);
}
