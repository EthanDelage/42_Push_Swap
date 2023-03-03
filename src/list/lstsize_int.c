/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:56:54 by edelage           #+#    #+#             */
/*   Updated: 2022/11/29 18:59:05 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lst_int.h"

size_t	lstsize_int(t_list_int *stack)
{
	size_t	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
