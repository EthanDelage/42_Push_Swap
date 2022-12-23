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

# include "../libft/includes/libft.h"
# include "parsing.h"
# include "lst_int.h"

void	sort_3(t_list_int **stack_a);
void	sort_7(t_list_int **stack_a);
void	calculate_operation(t_list_int **stack_a);
int		calculate_best_sort(t_list_int *stack_a);

#endif
