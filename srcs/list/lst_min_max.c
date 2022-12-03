/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_min_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 02:51:35 by edelage           #+#    #+#             */
/*   Updated: 2022/12/03 02:51:36 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lst_int.h"

int	lst_min_int(t_list_int *start)
{
	int	min;

	min = start->content;
	while (start)
	{
		if (start->content < min)
			min = start->content;
		start = start->next;
	}
	return (min);
}

int	lst_max_int(t_list_int *start)
{
	int	max;

	max = start->content;
	while (start)
	{
		if (start->content > max)
			max = start->content;
		start = start->next;
	}
	return (max);
}
