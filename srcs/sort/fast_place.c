/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:12:43 by edelage           #+#    #+#             */
/*   Updated: 2022/12/02 17:12:46 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

size_t	nb_move_up_b(size_t size_b, size_t index)
{
	size_t	count;

	count = 0;
	while ((index + count) % size_b != 0 && (index - count) % size_b != 0)
		count++;
	return (count);
}

size_t	nb_move_great_place(t_list_int *stack_a, int content)
{
	size_t	count;

	count = 0;
}

size_t	nb_move_for_place(t_list_int *stack_a, t_list_int *stack_b, int content)
{
	const size_t	size_b = lstsize_int(stack_b);
	const ssize_t	index_content = lst_search_int(stack_b, content);
	size_t			count;

	(void) stack_a;
	printf("\nsize_b: %ld, index: %ld", size_b, index_content);
	count = nb_move_up_b(size_b, index_content);
	printf("\ncount = %ld\n", count);
	return (count);
}

void	get_index_fast_place(t_list_int *stack_a, t_list_int *stack_b)
{
	const size_t	size_a = lstsize_int(stack_a);
	const size_t	size_b = lstsize_int(stack_b);

	(void) size_a;
	(void) size_b;
}
