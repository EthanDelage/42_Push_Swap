/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_int_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:46:18 by edelage           #+#    #+#             */
/*   Updated: 2022/11/29 21:47:07 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lst_int.h"

void	r_one(t_list_int **stack)
{
	t_list_int	*last;

	last = lstlast_int(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
}

void	rr_one(t_list_int **stack)
{
	t_list_int	*elem_before_last;

	elem_before_last = before_last(*stack);
	elem_before_last->next->next = *stack;
	*stack = elem_before_last->next;
	elem_before_last->next = NULL;
}

void	rr(t_list_int **stack_a, t_list_int **stack_b)
{
	r_one(stack_a);
	r_one(stack_b);
}

void	rrr(t_list_int **stack_a, t_list_int **stack_b)
{
	rr_one(stack_a);
	rr_one(stack_b);
}
