/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:12:42 by edelage           #+#    #+#             */
/*   Updated: 2022/11/30 00:05:53 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_in_b(t_list_int **stack_a, t_list_int **stack_b, size_t size_a,
		int max_not_push)
{
	size_t	count;
	int		last_rotate;
	int		changed;

	count = 0;
	last_rotate = -1;
	while (count < size_a)
	{
		changed = 1;
		while (changed)
		{
			changed = 0;
			if (lstsize_int(*stack_b) && (*stack_b)->content == last_rotate + 1)
			{
				changed = 1;
				last_rotate++;
				ft_putstr_fd("pa\n", 1);
				p_one(stack_b, stack_a);
				ft_putstr_fd("ra\n", 1);
				r_one(stack_a);
			}
			if (lstsize_int(*stack_b) > 1 && (*stack_b)->next->content == last_rotate + 1)
			{
				changed = 1;
				last_rotate++;
				ft_putstr_fd("sb\n", 1);
				s_one(stack_b);
				ft_putstr_fd("pa\n", 1);
				p_one(stack_b, stack_a);
				ft_putstr_fd("ra\n", 1);
				r_one(stack_a);
			}
		}
		if ((*stack_a)->content == last_rotate + 2
			&& (*stack_a)->next->content == last_rotate + 1)
		{
			ft_putstr_fd("sa\n", 1);
			s_one(stack_a);
		}
		if ((last_rotate == -1 && max_not_push >= (*stack_a)->content)
			|| (*stack_a)->content == last_rotate + 1)
		{
			last_rotate = (*stack_a)->content;
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
	const size_t	nb_arg = lstsize_int(*stack_a);
	t_list_int		*stack_b;

	stack_b = NULL;
	push_in_b(stack_a, &stack_b, nb_arg, nb_arg / 2);
	ft_putstr_fd("b:\n", 1);
	lst_display_int(stack_b);
	lstclear_int(&stack_b);
}
