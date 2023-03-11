/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:12:42 by edelage           #+#    #+#             */
/*   Updated: 2022/12/23 15:33:31 by edelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	insert_in_sorted_list(t_list_int **stack_a, t_list_int **stack_b, size_t index_min);
int	get_best_val_to_sort(t_list_int *stack_a, t_list_int *stack_b, size_t index_min);
void	sort_with_rr(t_list_int **stack_a, t_list_int **stack_b, t_move move);
void	sort_with_rrr(t_list_int **stack_a, t_list_int **stack_b, t_move move);
void	sort_with_rotate(t_list_int **stack_a, t_list_int **stack_b, t_move move);
size_t	get_index_min(t_list_int *stack_a);

size_t	get_index_to_insert(t_list_int *stack_a, size_t index_min, int value);
size_t	nb_move_to_sort(t_list_int *stack_a, t_list_int *stack_b, size_t index_min, int value);
t_move	get_move_of_value(t_list_int *stack_a, t_list_int *stack_b, size_t index_min, int value);
void	display(t_list_int *stack);
void	display_both(t_list_int *stack_a, t_list_int *stack_b);

#include <stdio.h>
void	calculate_operation(t_list_int **stack_a)
{
	t_list_int		*stack_b;
	size_t			index_min;
	size_t			lst_size = 3;

	stack_b = sort_into_chunk(stack_a);
	sort_3(stack_a);
	while (stack_b)
	{
		index_min = get_index_min(*stack_a);
		insert_in_sorted_list(stack_a, &stack_b, index_min);
		lst_size++;
	}
	if (lst_get_index(*stack_a, 0) < lstsize_int(*stack_a) / 2)
	{
		while ((*stack_a)->content != 0)
		{
			r_one(stack_a);
			ft_putstr_fd("ra\n", 1);
		}
	}
	else
	{
		while ((*stack_a)->content != 0)
		{
			rr_one(stack_a);
			ft_putstr_fd("rra\n", 1);
		}
	}
}

static void	insert_in_sorted_list(t_list_int **stack_a, t_list_int **stack_b, size_t index_min)
{
	const int		value = get_best_val_to_sort(*stack_a, *stack_b, index_min);
	const size_t	nb_move = nb_move_to_sort(*stack_a, *stack_b, index_min, value);
	const t_move	move = get_move_of_value(*stack_a, *stack_b, index_min, value);

	if (ft_max((int) move.ra, (int) move.rb) == (int) nb_move)
		sort_with_rr(stack_a, stack_b, move);
	else if (ft_max((int) move.rrb, (int) move.rra) == (int) nb_move)
		sort_with_rrr(stack_a, stack_b, move);
	else
		sort_with_rotate(stack_a, stack_b, move);
}

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

void	sort_with_rotate(t_list_int **stack_a, t_list_int **stack_b, t_move move)
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
	p_one(stack_b, stack_a);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

size_t	get_index_min(t_list_int *stack_a)
{
	int 	min;
	size_t	index;
	size_t	count;

	min = stack_a->content;
	index = 0;
	count = 0;
	while (stack_a)
	{
		if (min > stack_a->content)
		{
			min = stack_a->content;
			index = count;
		}
		stack_a = stack_a->next;
		count++;
	}
	return (index);
}
