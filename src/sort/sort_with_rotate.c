/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_with_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethan <ethan@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:14:00 by ethan             #+#    #+#             */
/*   Updated: 2023/03/12 19:14:00 by ethan            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	rotate_stack_a(t_list_int **stack_a, t_move move);
static void	rotate_stack_b(t_list_int **stack_b, t_move move);

void	sort_with_rr(t_list_int **stack_a, t_list_int **stack_b, t_move move)
{
	size_t	count;

	count = 0;
	while (count != move.rb && count != move.ra)
	{
		r_one(stack_a);
		r_one(stack_b);
		ft_putstr_fd("rr\n", STDOUT_FILENO);
		count++;
	}
	while (count < move.rb)
	{
		r_one(stack_b);
		ft_putstr_fd("rb\n", STDOUT_FILENO);
		count++;
	}
	while (count < move.ra)
	{
		r_one(stack_a);
		ft_putstr_fd("ra\n", STDOUT_FILENO);
		count++;
	}
	p_one(stack_b, stack_a);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	sort_with_rrr(t_list_int **stack_a, t_list_int **stack_b, t_move move)
{
	size_t	count;

	count = 0;
	while (count != move.rrb && count != move.rra)
	{
		rr_one(stack_a);
		rr_one(stack_b);
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
		count++;
	}
	while (count < move.rrb)
	{
		rr_one(stack_b);
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
		count++;
	}
	while (count < move.rra)
	{
		rr_one(stack_a);
		ft_putstr_fd("rra\n", STDOUT_FILENO);
		count++;
	}
	p_one(stack_b, stack_a);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	sort_with_rotate(t_list_int **stack_a, t_list_int **stack_b,
			t_move move)
{
	rotate_stack_a(stack_a, move);
	rotate_stack_b(stack_b, move);
	p_one(stack_b, stack_a);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

static void	rotate_stack_a(t_list_int **stack_a, t_move move)
{
	size_t	count;

	count = 0;
	if (move.ra > move.rra)
	{
		while (count < move.rra)
		{
			rr_one(stack_a);
			ft_putstr_fd("rra\n", STDOUT_FILENO);
			count++;
		}
	}
	else
	{
		while (count < move.ra)
		{
			r_one(stack_a);
			ft_putstr_fd("ra\n", STDOUT_FILENO);
			count++;
		}
	}
}

static void	rotate_stack_b(t_list_int **stack_b, t_move move)
{
	size_t	count;

	count = 0;
	if (move.rb > move.rrb)
	{
		while (count < move.rrb)
		{
			rr_one(stack_b);
			ft_putstr_fd("rrb\n", STDOUT_FILENO);
			count++;
		}
	}
	else
	{
		while (count < move.rb)
		{
			r_one(stack_b);
			ft_putstr_fd("rb\n", STDOUT_FILENO);
			count++;
		}
	}
}
