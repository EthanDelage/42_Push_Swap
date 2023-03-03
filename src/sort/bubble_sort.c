/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:28:26 by edelage           #+#    #+#             */
/*   Updated: 2022/11/29 21:45:43 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static	void	swap_value(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	bubble_sort(int *array, size_t nb_elem)
{
	int		changed;
	size_t	index;

	changed = 1;
	while (changed)
	{
		changed = 0;
		index = 0;
		while (nb_elem > 0 && index < nb_elem - 1)
		{
			if (array[index] > array[index + 1])
			{
				swap_value(&array[index], &array[index + 1]);
				changed = 1;
			}
			index++;
		}
	}
}	
