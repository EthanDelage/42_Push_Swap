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

static size_t	calculate_rr(size_t index_val, size_t index_where_insert);
static size_t	calculate_rrr(size_t size_a, size_t size_b, size_t index_val, size_t index_where_insert);
static size_t	get_index_to_insert(t_list_int *stack_a, size_t index_min, int value);


#include <stdio.h>
size_t	nb_move_to_sort(t_list_int *stack_a, t_list_int *stack_b, size_t index_min, int value)
{
	const size_t	size_a = lstsize_int(stack_a);
	const size_t	size_b = lstsize_int(stack_b);
	const size_t	index_val = lst_get_index(stack_b, value);
	const size_t	index_where_insert = get_index_to_insert(stack_a, index_min, value);
	size_t			nb_move;

	printf("index_min: %zu\nindex to insert: %zu\n", index_min, index_where_insert);
	nb_move = calculate_rr(index_val, index_where_insert);
	printf("nb_move with rr: %zu\n", nb_move);
	if (calculate_rrr(size_a, size_b, index_val, index_where_insert) < nb_move)
	{
		nb_move = calculate_rrr(size_a, size_b, index_val, index_where_insert);
		printf("nb_move with rrr: %zu\n", nb_move);
	}
	/*calculate nb_move with only ra rb rra rrb*/
	return (nb_move);
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

static size_t	calculate_rr(size_t index_val, size_t index_where_insert)
{
	size_t	nb_move;

	nb_move = ft_min((int) index_val, (int) index_where_insert);
	nb_move += ft_abs((int) index_val - (int) index_where_insert);
	return (nb_move + 1);
}

static size_t	calculate_rrr(size_t size_a, size_t size_b, size_t index_val, size_t index_where_insert)
{
	size_t	nb_move;

	printf("idx insert: %zu\n", index_where_insert);
	nb_move = ft_min((int) (size_a - index_where_insert), (int) (size_b - index_val));
	printf("test: %zu\n", nb_move);
	nb_move += ft_abs((int) (size_a - index_where_insert - (size_b - index_val)));
	return (nb_move + 1);
}
