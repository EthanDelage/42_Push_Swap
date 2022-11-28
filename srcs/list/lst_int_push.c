/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_int_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:04:14 by edelage           #+#    #+#             */
/*   Updated: 2022/11/28 18:36:54 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lst_int.h"

void	push(t_list_int **stack, t_list_int **stack_where_push)
{
	t_list_int	*tmp;

	tmp = *stack;
	*stack = *stack->next;
	tmp->next = *stack_where_push;
	*stack_where_push = tmp;
}
