/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 00:00:00 by edelage           #+#    #+#             */
/*   Updated: 2023/03/04 00:00:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}
