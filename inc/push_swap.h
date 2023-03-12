/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:07:58 by edelage           #+#    #+#             */
/*   Updated: 2022/12/23 15:38:40 by edelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <errno.h>
# include <stdlib.h>

# include "libft.h"
# include "parsing.h"
# include "lst_int.h"

typedef struct s_move
{
	size_t	ra;
	size_t	rb;
	size_t	rra;
	size_t	rrb;
}	t_move;

void		sort_3(t_list_int **stack_a);
void		sort_7(t_list_int **stack_a);
void		calculate_operation(t_list_int **stack_a);

t_list_int	*sort_into_chunk(t_list_int **stack_a);
size_t		nb_move_to_sort(t_list_int *stack_a, t_list_int *stack_b,
				int value);
t_move		get_move_of_value(t_list_int *stack_a, t_list_int *stack_b,
				int value);
int			get_best_val_to_sort(t_list_int *stack_a, t_list_int *stack_b);
void		sort_with_rr(t_list_int **stack_a, t_list_int **stack_b,
				t_move move);
void		sort_with_rrr(t_list_int **stack_a, t_list_int **stack_b,
				t_move move);
void		sort_with_rotate(t_list_int **stack_a, t_list_int **stack_b,
				t_move move);

#endif
