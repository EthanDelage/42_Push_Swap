/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_into_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:17:00 by edelage           #+#    #+#             */
/*   Updated: 2023/03/03 21:17:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

#include "stdio.h"

static int	get_chunk(int value, size_t nb_elem);
static void	move_to_first_chunk(t_list_int **stack_a);
static void	move_to_second_chunk(t_list_int **stack_a, t_list_int **stack_b);
static void	move_to_third_chunk(t_list_int **stack_a, t_list_int **stack_b);

t_list_int *sort_into_chunk(t_list_int **stack_a)
{
	t_list_int	*stack_b;
	size_t		nb_elem;
	size_t		count;
	int			chunk;

	nb_elem = lstsize_int(*stack_a);
	stack_b = NULL;
	count = 0;
	while (count < nb_elem)
	{
		chunk = get_chunk((*stack_a)->content, nb_elem);
		if (chunk == 0)
			move_to_third_chunk(stack_a, &stack_b);
		else if (chunk == 1)
			move_to_second_chunk(stack_a, &stack_b);
		else
			move_to_first_chunk(stack_a);
		count++;
	}
	while (lstsize_int(*stack_a) > 3)
	{
		p_one(stack_a, &stack_b);
		write(STDOUT_FILENO, "pb\n", 3);
	}
	return (stack_b);
}

static int	get_chunk(int value, size_t nb_elem)
{
	return (value * 3 / (int) nb_elem);
}

static void	move_to_first_chunk(t_list_int **stack_a)
{
	r_one(stack_a);
	write(STDOUT_FILENO, "ra\n", 3);
}

static void	move_to_second_chunk(t_list_int **stack_a, t_list_int **stack_b)
{
	p_one(stack_a, stack_b);
	write(STDOUT_FILENO, "pb\n", 3);
}

static void	move_to_third_chunk(t_list_int **stack_a, t_list_int **stack_b)
{
	p_one(stack_a, stack_b);
	write(STDOUT_FILENO, "pb\n", 3);
	r_one(stack_b);
	write(STDOUT_FILENO, "rb\n", 3);
}
