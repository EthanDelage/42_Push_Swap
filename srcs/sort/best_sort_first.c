/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_sort_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:04:57 by edelage           #+#    #+#             */
/*   Updated: 2022/12/23 15:45:45 by edelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static size_t	calculate_nb_sort(t_list_int *stack_a)
{
	size_t	nb_sort;
	int		last_elem_sort;

	nb_sort = 1;
	last_elem_sort = stack_a->content;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (stack_a->content > last_elem_sort)
		{
			nb_sort++;
			last_elem_sort = stack_a->content;
		}
		stack_a = stack_a->next;
	}
	return (nb_sort);
}

int	calculate_best_sort(t_list_int *stack_a)
{
	int		best_index;
	size_t	nb_sort;
	size_t	nb_best_sort;

	best_index = stack_a->content;
	nb_best_sort = 1;
	while (stack_a)
	{
		nb_sort = calculate_nb_sort(stack_a);
		if (nb_sort > nb_best_sort)
		{
			nb_best_sort = nb_sort;
			best_index = stack_a->content;
		}
		stack_a = stack_a->next;
	}
	return (best_index);
}
