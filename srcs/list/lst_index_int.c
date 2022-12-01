/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_index_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:02:21 by edelage           #+#    #+#             */
/*   Updated: 2022/12/01 19:37:07 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lst_int.h"

t_list_int	*lst_index_int(t_list_int *stack, size_t index)
{
	size_t	count;

	count = 0;
	while (stack && count < index)
	{
		count++;
		stack = stack->next;
	}
	return (stack);
}
