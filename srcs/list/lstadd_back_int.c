/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 00:46:03 by edelage           #+#    #+#             */
/*   Updated: 2022/11/28 02:52:30 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lst_int.h"

void	lstadd_back_int(t_list_int **last, t_list_int *new_elem)
{
	if (!last || !new_elem)
		return ;
	if (*last == NULL)
		*last = new_elem;
	else
		(*last)->next = new_elem;
}
