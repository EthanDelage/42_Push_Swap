/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:51:06 by edelage           #+#    #+#             */
/*   Updated: 2022/11/29 19:42:26 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <errno.h>
# include <stdlib.h>

# include "../libft/includes/libft.h"
# include "lst_int.h"

int			next_number(const char *str);
int			check_number(const char *str);
void		print_error_msg(int error_code);
t_list_int	*parse_arg(int argc, char **argv);
void		free_for_error(t_list_int **start);
int			convert_by_index(t_list_int *stack);
int			check_multi_number(const char *str);
void		bubble_sort(int *array, size_t nb_elem);

#endif
