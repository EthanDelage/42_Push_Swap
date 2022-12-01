/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:44:25 by edelage           #+#    #+#             */
/*   Updated: 2022/12/01 13:46:37 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	check_move_b(t_list_int **stack_a, t_list_int **stack_b, int last_rotate)
{
	int	changed;

	changed = 1;
	while (changed)
	{
		changed = 0;
		if ((lstsize_int(*stack_b) && (*stack_b)->content == last_rotate + 1)
			|| (lstsize_int(*stack_b) > 1
				&& (*stack_b)->next->content == last_rotate + 1))
		{
			changed = 1;
			last_rotate++;
			if (lstsize_int(*stack_b) && (*stack_b)->content == last_rotate + 1)
			{
				ft_putstr_fd("sb\n", 1);
				s_one(stack_b);
			}
			ft_putstr_fd("pa\n", 1);
			p_one(stack_b, stack_a);
			ft_putstr_fd("ra\n", 1);
			r_one(stack_a);
		}
	}
	return (last_rotate);
}

void	push_in_b(t_list_int **stack_a, t_list_int **stack_b, size_t size_a,
		int max_not_push)
{
	size_t	count;
	int		last_rotate;

	count = 0;
	last_rotate = -1;
	while (count < size_a)
	{
		if (lst_issort_int(*stack_a))
			return ;
		last_rotate = check_move_b(stack_a, stack_b, last_rotate);
		if (count < size_a - 1 && (*stack_a)->next->content == last_rotate + 1)
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
	last_rotate = check_move_b(stack_a, stack_b, last_rotate);
}

int	calc_elem_sort(t_list_int *stack_a, int max_not_push)
{
	int	elem_sort;
	int	last_rotate;

	elem_sort = 0;
	last_rotate = -1;
	while (stack_a)
	{
		if ((last_rotate == -1 && max_not_push >= stack_a->content)
			|| stack_a->content == last_rotate + 1)
		{
			last_rotate = stack_a->content;
			elem_sort += 1;
		}
		stack_a = stack_a->next;
	}
	return (elem_sort);
}

size_t	calc_max_not_push(t_list_int **stack_a)
{
	t_list_int		*cpy_stack;
	size_t			nb_elem_sort;
	size_t			max_nb_sort;
	size_t			best_index;

	cpy_stack = *stack_a;
	best_index = cpy_stack->content;
	max_nb_sort = calc_elem_sort(*stack_a, cpy_stack->content);
	cpy_stack = cpy_stack->next;
	while (cpy_stack)
	{
		nb_elem_sort = calc_elem_sort(*stack_a, cpy_stack->content);
		if (nb_elem_sort > max_nb_sort)
		{
			max_nb_sort = nb_elem_sort;
			best_index = lst_search_int(*stack_a, cpy_stack->content);
		}
		cpy_stack = cpy_stack->next;
	}
	return (best_index);
}
