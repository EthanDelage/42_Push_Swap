/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_front_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 02:51:50 by edelage           #+#    #+#             */
/*   Updated: 2022/11/28 03:55:21 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lst_int.h"

void	lstadd_front_int(t_list_int **start, t_list_int *new_elem)
{
	if (!start || !new_elem)
		return ;
	if (*start)
		new_elem->next = *start;
	*start = new_elem;
}
