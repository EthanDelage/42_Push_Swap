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
void	display(t_list_int *stack);
size_t	get_index_to_insert(t_list_int *stack_a, size_t index_min, int value);

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
	return (nb_move);
}

t_move	get_move_of_value(t_list_int *stack_a, t_list_int *stack_b, size_t index_min, int value)
{
	t_move			move;

	move.ra = get_index_to_insert(stack_a, index_min, value);
	move.rb = lst_get_index(stack_b, value);
	move.rra = lstsize_int(stack_a) - move.ra;
	if (stack_b->next == NULL)
		move.rrb = 0;
	else
		move.rrb = lstsize_int(stack_b) - move.rb;
	return (move);
}

ssize_t get_index_after(t_list_int *stack_a, int value);
ssize_t get_index_before(t_list_int *stack_a, int value);

size_t	get_index_to_insert(t_list_int *stack_a, size_t index_min, int value)
{
	ssize_t	index_before;
	ssize_t	index_after;
	const size_t	lst_size = lstsize_int(stack_a);

	(void) index_min;
	index_after = get_index_after(stack_a, value);
	if (index_after != -1)
		return (index_after);
	index_before = get_index_before(stack_a, value);
	return ((index_before + 1) % lst_size);
}

ssize_t	get_index_before(t_list_int *stack_a, int value)
{
	size_t	count;
	int		value_before;
	ssize_t	index_before;

	index_before = -1;
	value_before = lst_min_int(stack_a);
	count = 0;
	while (stack_a)
	{
		if (stack_a->content < value && stack_a->content >= value_before)
		{
			value_before = stack_a->content;
			index_before = count;
		}
		count++;
		stack_a = stack_a->next;
	}
	return (index_before);
}

#include <stdio.h>

ssize_t get_index_after(t_list_int *stack_a, int value)
{
	size_t	count;
	int		value_after;
	ssize_t	index_after;

	index_after = -1;
	value_after = lst_max_int(stack_a);
	count = 0;
	while (stack_a)
	{
		if (stack_a->content > value && stack_a->content <= value_after)
		{
			index_after = count;
			value_after = stack_a->content;
		}
		count++;
		stack_a = stack_a->next;
	}
	return (index_after);
}
