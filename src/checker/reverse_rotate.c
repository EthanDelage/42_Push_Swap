/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethan <ethan@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:28:00 by ethan             #+#    #+#             */
/*   Updated: 2023/03/12 22:28:00 by ethan            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	rra(t_list_int **stack_a, t_list_int **stack_b)
{
	(void) stack_b;
	rr_one(stack_a);
}

void	rrb(t_list_int **stack_a, t_list_int **stack_b)
{
	(void) stack_a;
	rr_one(stack_b);
}

void	rrr(t_list_int **stack_a, t_list_int **stack_b)
{
	rr_one(stack_a);
	rr_one(stack_b);
}
