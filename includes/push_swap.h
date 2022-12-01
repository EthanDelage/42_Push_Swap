/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:07:58 by edelage           #+#    #+#             */
/*   Updated: 2022/12/01 13:46:36 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <errno.h>
# include <stdlib.h>

# include "../libft/includes/libft.h"
# include "parsing.h"
# include "lst_int.h"

void	push_in_b(t_list_int **stack_a, t_list_int **stack_b, size_t size_a,
			int max_not_push);
size_t	calc_max_not_push(t_list_int **stack_a);
void	calculate_operation(t_list_int **stack_a);

#endif
