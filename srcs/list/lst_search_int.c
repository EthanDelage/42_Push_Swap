/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_search_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:33:11 by edelage           #+#    #+#             */
/*   Updated: 2022/11/30 13:37:57 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lst_int.h"

ssize_t	lst_search_int(t_list_int *start, int to_find)
{
	size_t	count;

	count = 0;
	while (start && start->content != to_find)
	{
		start = start->next;
		count++;
	}
	if (start != NULL)
		return ((ssize_t) count);
	return (-1);
}
