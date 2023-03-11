/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:57:22 by edelage           #+#    #+#             */
/*   Updated: 2022/12/11 17:18:34 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	display(t_list_int *stack)
{
	while (stack)
	{
		ft_putnbr_fd(stack->content, 1);
		ft_putchar_fd(' ', 1);
		stack = stack->next;
	}
	ft_putchar_fd('\n', 1);
}

void	display_both(t_list_int *stack_a, t_list_int *stack_b)
{
	display(stack_a);
	display(stack_b);
}

int	main(int argc, char **argv)
{
	t_list_int	*stack_a;

	if (argc == 1)
		return (0);
	stack_a = parse_arg(argc, argv);
	if (lst_issort_int(stack_a))
	{
		lstclear_int(&stack_a);
		return (0);
	}
	if (lstsize_int(stack_a) == 3)
		sort_3(&stack_a);
	else if (lstsize_int(stack_a) <= 7 && lstsize_int(stack_a) > 3)
		sort_7(&stack_a);
	else
		calculate_operation(&stack_a);
	lstclear_int(&stack_a);
	return (0);
}
