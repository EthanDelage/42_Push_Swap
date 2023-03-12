/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethan <ethan@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:22:00 by ethan             #+#    #+#             */
/*   Updated: 2023/03/12 22:22:00 by ethan            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	pa(t_list_int **stack_a, t_list_int **stack_b)
{
	p_one(stack_b, stack_a);
}

void	pb(t_list_int **stack_a, t_list_int **stack_b)
{
	p_one(stack_a, stack_b);
}

void	sa(t_list_int **stack_a, t_list_int **stack_b)
{
	(void) stack_b;
	s_one(stack_a);
}

void	sb(t_list_int **stack_a, t_list_int **stack_b)
{
	(void) stack_a;
	s_one(stack_b);
}

void	ss(t_list_int **stack_a, t_list_int **stack_b)
{
	s_one(stack_a);
	s_one(stack_b);
}
