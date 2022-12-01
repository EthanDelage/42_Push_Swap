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

void	push_elem_top(t_list_int **stack, size_t size_stack, int content,
	size_t index)
{
	if (index <= (size_stack + 1) / 2)
	{
		while ((*stack)->content != content)
		{
			ft_putstr_fd("rb\n", 1);
			r_one(stack);
		}
	}
	else
	{
		while ((*stack)->content != content)
		{
			ft_putstr_fd("rrb\n", 1);
			rr_one(stack);
		}
	}
}

#include <stdio.h>
void	check_fast_place(t_list_int **stack_a, t_list_int **stack_b) 
{
	size_t			count;
	size_t			size_b;
	int				elem_top;
	int				elem_bottom;
	t_list_int		*elem;

	size_b = lstsize_int(*stack_b);
	elem_top = (*stack_a)->content;
	elem_bottom = lstlast_int(*stack_a)->content;
	count = 0;
	while (count < lstsize_int(*stack_b) && !lst_issort_size_int(*stack_a, lstsize_int(*stack_a) + lstsize_int(*stack_b) + 1))
	{
		elem = lst_index_int(*stack_b, count);
		if (elem && (elem->content == elem_top - 1 || elem->content == elem_bottom + 1))
		{
			count = 0;
			push_elem_top(stack_b, lstsize_int(*stack_b), elem->content, count);
			ft_putstr_fd("pa\n", 1);
			p_one(stack_b, stack_a);
			if (elem->content == elem_top - 1)
			{
				elem_top = (*stack_a)->content;
			}
			else
			{
				elem_bottom = elem->content;
				ft_putstr_fd("ra\n", 1);
				r_one(stack_a);
			}
		}
		count++;
	}
}

void	calculate_operation(t_list_int **stack_a)
{
	size_t	nb_arg = lstsize_int(*stack_a);
	t_list_int		*stack_b;

	stack_b = NULL;
	push_in_b(stack_a, &stack_b, nb_arg, calc_max_not_push(stack_a));
	check_fast_place(stack_a, &stack_b);
	ft_putstr_fd("b:\n", 1);
	lst_display_int(stack_b);
	lstclear_int(&stack_b);
}
