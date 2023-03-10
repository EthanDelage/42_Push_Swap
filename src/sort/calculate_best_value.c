/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_best_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 00:08:00 by edelage           #+#    #+#             */
/*   Updated: 2023/03/04 00:08:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

size_t nb_move_to_sort(t_list_int *stack_a, t_list_int *stack_b, size_t index_min, int value);

int	get_best_val_to_sort(t_list_int *stack_a, t_list_int *stack_b, size_t index_min)
{
	int		best_value;
	t_list_int	*current;
	size_t	best_nb_move;
	size_t	nb_move;

	best_value = stack_b->content;
	best_nb_move = nb_move_to_sort(stack_a, stack_b, index_min, stack_b->content);
	current = stack_b->next;
	while (current)
	{
		nb_move = nb_move_to_sort(stack_a, stack_b, index_min, current->content);
		if (nb_move > best_nb_move)
		{
			best_value = current->content;
			best_nb_move = nb_move;
		}
		current = current->next;
	}
	return (best_value);
}


