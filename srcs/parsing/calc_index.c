/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:26:58 by edelage           #+#    #+#             */
/*   Updated: 2022/11/29 22:09:38 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

static int	*copy_stack(t_list_int *stack)
{
	int		*array;
	size_t	index;

	array = (int *) malloc(sizeof(int) * lstsize_int(stack));
	if (array == NULL)
		return (NULL);
	index = 0;
	while (stack)
	{
		array[index] = stack->content;
		stack = stack->next;
		index++;
	}
	return (array);
}

static size_t	get_index(int *array, int to_find)
{
	size_t	index;

	index = 0;
	while (array[index] != to_find)
		index++;
	return (index);
}

int	convert_by_index(t_list_int *stack)
{
	int	*array;

	array = copy_stack(stack);
	if (array == NULL)
		return (FAILURE);
	bubble_sort(array, lstsize_int(stack));
	while (stack)
	{
		stack->content = get_index(array, stack->content);
		stack = stack->next;
	}
	free(array);
	return (SUCCESS);
}
