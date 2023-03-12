/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethan <ethan@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:27:00 by ethan             #+#    #+#             */
/*   Updated: 2023/03/12 22:27:00 by ethan            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	ra(t_list_int **stack_a, t_list_int **stack_b)
{
	(void) stack_b;
	r_one(stack_a);
}

void	rb(t_list_int **stack_a, t_list_int **stack_b)
{
	(void) stack_a;
	r_one(stack_b);
}

void	rr(t_list_int **stack_a, t_list_int **stack_b)
{
	r_one(stack_a);
	r_one(stack_b);
}
