/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlast_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 02:56:34 by edelage           #+#    #+#             */
/*   Updated: 2022/11/28 02:58:36 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lst_int.h"

t_list_int	*lstlast_int(t_list_int *start)
{
	if (!start)
		return (NULL);
	while (start->next)
		start = start->next;
	return (start);
}
