/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_int.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 00:38:36 by edelage           #+#    #+#             */
/*   Updated: 2022/12/01 18:58:17 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_INT_H
# define LST_INT_H

# include <stdlib.h>
# include "../libft/includes/libft.h"

# define SUCCESS	0
# define FAILURE	1

typedef struct s_list_int
{
	int					content;
	struct s_list_int	*next;
}				t_list_int;

t_list_int	*lstnew_int(int content);
int			lst_min_int(t_list_int *start);
int			lst_max_int(t_list_int *start);
size_t		lstsize_int(t_list_int *stack);
t_list_int	*before_last(t_list_int *stack);
t_list_int	*lstlast_int(t_list_int *start);
void		lstclear_int(t_list_int **start);
void		lstadd_front_int(t_list_int **start, t_list_int *new_elem);

/* ==== Operations ==== */
void		s_one(t_list_int **stack);
void		r_one(t_list_int **stack);
void		rr_one(t_list_int **stack);
void		ss(t_list_int **stack_a, t_list_int **stack_b);
void		rr(t_list_int **stack_a, t_list_int **stack_b);
void		rrr(t_list_int **stack_a, t_list_int **stack_b);
void		p_one(t_list_int **stack, t_list_int **stack_where_push);

#endif
