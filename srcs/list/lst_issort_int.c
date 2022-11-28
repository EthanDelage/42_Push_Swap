/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_issort_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 00:55:47 by edelage           #+#    #+#             */
/*   Updated: 2022/11/28 01:08:26 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lst_int.h"

int	lst_issort_int(t_list_int *start)
{
	int	previous_val;

	if (!start)
		return (-1);
	previous_val = start->content;
	start = start->next;
	while (start)
	{
		if (start->content >= previous_val)
			return (0);
		previous_val = start->content;
		start = start->next;
	}
	return (1);
}
