/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 00:50:49 by edelage           #+#    #+#             */
/*   Updated: 2022/11/28 04:15:59 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lst_int.h"

void	lstclear_int(t_list_int **start)
{
	t_list_int	*tmp;

	if (!start || !*start)
		return ;
	tmp = 
	while (*start)
	{
		tmp = (*start)->next;
		free(tmp);
		*start = tmp;
	}
	*start = NULL;
}
