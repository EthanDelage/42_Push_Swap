/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_int_sa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:36:18 by edelage           #+#    #+#             */
/*   Updated: 2022/11/28 17:57:55 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lst_int.h"

void	swap(t_list_int **stack)
{
	t_list_int	*tmp;

	tmp = (*stack)->next;
	*stack->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	swap_swap(t_list_int **stack_a, t_list_int **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
