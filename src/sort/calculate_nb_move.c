/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_nb_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 00:11:00 by edelage           #+#    #+#             */
/*   Updated: 2023/03/04 00:11:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static size_t	get_index_to_insert(t_list_int *stack_a, size_t index_min, int value);

size_t	nb_move_to_sort(t_list_int *stack_a, t_list_int *stack_b, size_t index_min, int value)
{
	t_move			move;
	size_t			nb_move;

	move.ra = get_index_to_insert(stack_a, index_min, value);
	move.rb = lst_get_index(stack_b, value);
	move.rra = lstsize_int(stack_a) - move.ra;
	move.rrb = lstsize_int(stack_b) - move.rb;
	nb_move = ft_min(ft_max(move.ra, move.rb), ft_max(move.rra, move.rrb));
	nb_move = ft_min(nb_move, ft_min(move.ra, move.rra) + ft_min(move.rb, move.rrb));
	//maybe check with ra and rrb or rra and rb
	return (nb_move);
}

t_move	get_move_of_value(t_list_int *stack_a, t_list_int *stack_b, size_t index_min, int value)
{
	t_move			move;

	move.ra = get_index_to_insert(stack_a, index_min, value);
	move.rb = lst_get_index(stack_b, value);
	move.rra = lstsize_int(stack_a) - move.ra;
	move.rrb = lstsize_int(stack_b) - move.rb;
	return (move);
}

static size_t	get_index_to_insert(t_list_int *stack_a, size_t index_min, int value)
{
	size_t	index;

	index = 0;
	while (stack_a)
	{
		if (index + 1 == index_min && stack_a->content < value)
			return (index + 1);
		else if (index == index_min && stack_a->content > value)
			return (index);
		if (stack_a->content < value && stack_a->next && stack_a->next->content < value)
			return (index + 1);
		index++;
		stack_a = stack_a->next;
	}
	return (index);
}
