/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:51:06 by edelage           #+#    #+#             */
/*   Updated: 2022/11/28 05:21:01 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <errno.h>
# include <stdlib.h>

# include "../libft/includes/libft.h"
# include "lst_int.h"

int			check_number(const char *str);
void		print_error_msg(int error_code);
t_list_int	*parse_arg(int argc, char **argv);

#endif
