/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_issort_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:24:16 by edelage           #+#    #+#             */
/*   Updated: 2022/12/07 15:24:17 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lst_int.h"

int	lst_issort_int(t_list_int *stack_a)
{
	int	last_val;

	if (stack_a == NULL)
		return (1);
	last_val = stack_a->content;
	while (stack_a)
	{
		if (last_val > stack_a->content)
			return (0);
		last_val = stack_a->content;
		stack_a = stack_a->next;
	}
	return (1);
}
