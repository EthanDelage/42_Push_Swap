/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethan <ethan@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:28:00 by ethan             #+#    #+#             */
/*   Updated: 2023/03/12 21:28:00 by ethan            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

static int	execute_instruction(t_list_int **stack_a, t_list *instruction);
static int	execute_an_instruction(t_list_int **stack_a, t_list_int **stack_b,
				char *instruction);

int	main(int argc, char **argv)
{
	t_list_int	*stack_a;
	t_list		*instruction;
	int			return_value;

	if (argc == 1)
		return (0);
	stack_a = parse_arg(argc, argv);
	instruction = get_instruction();
	return_value = execute_instruction(&stack_a, instruction);
	if (return_value >= 0)
	{
		if (lst_issort_int(stack_a) && return_value == 0)
			write(STDOUT_FILENO, "OK\n", 3);
		else
			write(STDOUT_FILENO, "KO\n", 3);
	}
	lstclear_int(&stack_a);
	ft_lstclear(&instruction, free);
	if (return_value == -1)
		return (-1);
	return (0);
}

static int	execute_instruction(t_list_int **stack_a, t_list *instruction)
{
	t_list_int	*stack_b;

	stack_b = NULL;
	while (instruction)
	{
		if (execute_an_instruction(stack_a, &stack_b,
				instruction->content) == -1)
		{
			write(STDERR_FILENO, "Error\n", 6);
			return (-1);
		}
		instruction = instruction->next;
	}
	if (stack_b == NULL)
		return (0);
	lstclear_int(&stack_b);
	return (1);
}

typedef void	(*t_function)(t_list_int**, t_list_int**);

static int	execute_an_instruction(t_list_int **stack_a, t_list_int **stack_b,
				char *instruction)
{
	const char			*movement[] = {"sa\n", "sb\n", "ss\n",
		"pa\n", "pb\n", "ra\n", "rb\n", "rr\n",
		"rra\n", "rrb\n", "rrr\n", NULL};
	const t_function	function[] = {&sa, &sb, &ss, &pa,
		&pb, &ra, &rb, &rr, &rra, &rrb, &rrr};
	size_t				index;

	index = 0;
	while (movement[index])
	{
		if (ft_strcmp(movement[index], instruction) == 0)
		{
			(function[index])(stack_a, stack_b);
			return (0);
		}
		index++;
	}
	return (-1);
}
