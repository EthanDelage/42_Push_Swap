/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:51:06 by edelage           #+#    #+#             */
/*   Updated: 2022/11/28 03:09:19 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <errno.h>
# include <stdlib.h>

# include "../libft/includes/libft.h"
# include "lst_int.h"

void		print_error_msg(int error_code);
int			check_number(const char *str);
t_list_int	*init_a_stack(int argc, char **argv);

#endif
