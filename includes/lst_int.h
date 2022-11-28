/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_int.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 00:38:36 by edelage           #+#    #+#             */
/*   Updated: 2022/11/28 18:57:46 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_INT_H
# define LST_INT_H

# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct s_list_int
{
	int					content;
	struct s_list_int	*next;
}				t_list_int;

t_list_int	*lstnew_int(int content);
t_list_int	*before_last(t_list_int *stack);
t_list_int	*lstlast_int(t_list_int *start);
void		lstclear_int(t_list_int **start);
int			lst_issort_int(t_list_int *start);
void		lst_display_int(t_list_int *start);
void		lstadd_back_int(t_list_int **last, t_list_int *new_elem);
void		lstadd_front_int(t_list_int **start, t_list_int *new_elem);

/* ==== Operations ==== */
void		swap(t_list_int **stack);
void		swap_swap(t_list_int **stack_a, t_list_int **stack_b);
void		push(t_list_int **stack, t_list_int **stack_where_push);

#endif
