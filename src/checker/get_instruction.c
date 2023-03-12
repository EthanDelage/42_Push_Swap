/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethan <ethan@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:55:00 by ethan             #+#    #+#             */
/*   Updated: 2023/03/12 21:55:00 by ethan            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

static t_list	*lst_add_elem(t_list **head, void *content);

t_list	*get_instruction(void)
{
	t_list	*instruction;
	char	*line;

	instruction = NULL;
	line = get_next_line(STDIN_FILENO);
	if (errno)
		print_error_msg(errno);
	while (line)
	{
		if (lst_add_elem(&instruction, line) == NULL)
		{
			write(STDERR_FILENO, "Malloc error\n", 13);
			exit(errno);
		}
		line = get_next_line(STDIN_FILENO);
		if (errno)
		{
			ft_lstclear(&instruction, free);
			print_error_msg(errno);
		}
	}
	return (instruction);
}

static t_list	*lst_add_elem(t_list **head, void *content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (new == NULL)
	{
		ft_lstclear(head, free);
		return (NULL);
	}
	ft_lstadd_front(head, new);
	return (*head);
}
