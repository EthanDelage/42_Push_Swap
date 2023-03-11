/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_before_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:48:12 by edelage           #+#    #+#             */
/*   Updated: 2022/11/28 18:57:56 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lst_int.h"

t_list_int	*before_last(t_list_int *stack)
{
	if (!stack)
		return (NULL);
	if (!stack->next)
		return (stack);
	while (stack->next->next)
	{
		stack = stack->next;
	}
	return (stack);
}
