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

void	lstadd_back_int(t_list_int **lst, t_list_int *new)
{
	t_list_int	*elem;

	if (new == NULL || lst == NULL)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		elem = *lst;
		while (elem->next != NULL)
			elem = elem->next;
		elem->next = new;
	}
}