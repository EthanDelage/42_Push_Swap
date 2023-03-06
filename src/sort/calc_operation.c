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

static void	sort_one(t_list_int **stack_a, t_list_int **stack_b, size_t index_min);
static int	get_best_val_to_sort(t_list_int *stack_a, t_list_int *stack_b, size_t index_min);

size_t	nb_move_to_sort(t_list_int *stack_a, t_list_int *stack_b, size_t index_min, int value);
void	display(t_list_int *stack);

#include <stdio.h>
void	calculate_operation(t_list_int **stack_a)
{
	t_list_int		*stack_b;

	stack_b = sort_into_chunk(stack_a);
	sort_3(stack_a);
	printf("a\n");
	display(*stack_a);
	printf("b\n");
	display(stack_b);
	printf("nb_move: %zu\n", nb_move_to_sort(*stack_a, stack_b, 0, 2));
	(void) stack_b;
}
//
//static void	sort_one(t_list_int **stack_a, t_list_int **stack_b, size_t index_min)
//{
//	const int value = get_best_val_to_sort(*stack_a, *stack_b, index_min);
//}
