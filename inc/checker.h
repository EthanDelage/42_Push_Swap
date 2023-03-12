/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethan <ethan@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:29:00 by ethan             #+#    #+#             */
/*   Updated: 2023/03/12 21:29:00 by ethan            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "get_next_line.h"
# include "lst_int.h"
# include "parsing.h"
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>

t_list	*get_instruction(void);
void	pa(t_list_int **stack_a, t_list_int **stack_b);
void	pb(t_list_int **stack_a, t_list_int **stack_b);
void	sa(t_list_int **stack_a, t_list_int **stack_b);
void	sb(t_list_int **stack_a, t_list_int **stack_b);
void	ss(t_list_int **stack_a, t_list_int **stack_b);
void	ra(t_list_int **stack_a, t_list_int **stack_b);
void	rb(t_list_int **stack_a, t_list_int **stack_b);
void	rr(t_list_int **stack_a, t_list_int **stack_b);
void	rra(t_list_int **stack_a, t_list_int **stack_b);
void	rrb(t_list_int **stack_a, t_list_int **stack_b);
void	rrr(t_list_int **stack_a, t_list_int **stack_b);

#endif
