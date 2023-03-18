/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:12:42 by edelage           #+#    #+#             */
/*   Updated: 2022/12/23 15:33:31 by edelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	insert_in_sorted_list(t_list_int **stack_a, t_list_int **stack_b);
static void	raise_min(t_list_int **stack_a, size_t lst_size);

void	calculate_operation(t_list_int **stack_a)
{
	t_list_int		*stack_b;
	size_t			lst_size;

	stack_b = sort_into_chunk(stack_a);
	sort_3(stack_a);
	lst_size = 3;
	while (stack_b)
	{
		insert_in_sorted_list(stack_a, &stack_b);
		lst_size++;
	}
	raise_min(stack_a, lst_size);
}

static void	insert_in_sorted_list(t_list_int **stack_a, t_list_int **stack_b)
{
	const int		value = get_best_val_to_sort(*stack_a, *stack_b);
	const size_t	nb_move = nb_move_to_sort(*stack_a, *stack_b, value);
	const t_move	move = get_move_of_value(*stack_a, *stack_b, value);

	if (ft_max(move.ra, move.rb) == nb_move)
		sort_with_rr(stack_a, stack_b, move);
	else if (ft_max(move.rrb, move.rra) == nb_move)
		sort_with_rrr(stack_a, stack_b, move);
	else
		sort_with_rotate(stack_a, stack_b, move);
}

static void	raise_min(t_list_int **stack_a, size_t lst_size)
{
	if (lst_get_index(*stack_a, 0) < lst_size / 2)
	{
		while ((*stack_a)->content != 0)
		{
			r_one(stack_a);
			ft_putstr_fd("ra\n", 1);
		}
	}
	else
	{
		while ((*stack_a)->content != 0)
		{
			rr_one(stack_a);
			ft_putstr_fd("rra\n", 1);
		}
	}
}
