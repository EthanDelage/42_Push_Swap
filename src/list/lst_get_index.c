/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_get_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:23:00 by edelage           #+#    #+#             */
/*   Updated: 2023/03/03 22:23:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lst_int.h"

size_t	lst_get_index(t_list_int *stack, int val)
{
	size_t	index;

	index = 0;
	while (stack)
	{
		if (val == stack->content)
			return (index);
		index++;
		stack = stack->next;
	}
	return (index);
}
