/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_int_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:04:14 by edelage           #+#    #+#             */
/*   Updated: 2022/11/29 01:10:22 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lst_int.h"

void	p_one(t_list_int **stack, t_list_int **stack_where_push)
{
	t_list_int	*tmp;

	if (*stack == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = *stack_where_push;
	*stack_where_push = tmp;
}
