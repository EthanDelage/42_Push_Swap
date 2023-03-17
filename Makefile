# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 11:49:53 by edelage           #+#    #+#              #
#    Updated: 2022/12/23 15:25:31 by edelage          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***************************
#  Folders
# ***************************

INC_DIR =			inc/

SRC_DIR =			src/

BUILD_DIR =			.build/

DIR =				parsing/ \
					sort/ \
					list/ \

LIBFT_DIR =			libft/

# ***************************
#  Files
# ***************************

LIST =				list/lstadd_front_int.c \
					list/lstadd_back_int.c \
					list/lst_before_last.c \
					list/lst_issort_int.c \
					list/lst_int_rotate.c \
					list/lst_int_swap.c \
					list/lst_int_push.c \
					list/lstclear_int.c \
					list/lstsize_int.c \
					list/lstlast_int.c \
					list/lst_min_max.c \
					list/lstnew_int.c \
					list/lst_get_index.c \

SORT =				sort/exception.c \
					sort/bubble_sort.c \
					sort/sort_into_chunk.c \
					sort/sort_with_rotate.c \
					sort/calc_operation.c \
					sort/calculate_nb_move.c \
					sort/calculate_best_value.c \


PARSING =			parsing/check_number.c \
					parsing/calc_index.c \
					parsing/parsing.c \
					parsing/error.c \

SRCS =				$(PARSING) \
					$(SORT) \
					$(LIST) \
					main.c \

SRCS_BONUS =		$(PARSING) \
					$(LIST) \
					sort/bubble_sort.c \
					checker/checker.c \
					checker/get_instruction.c \
					checker/movement.c \
					checker/rotate.c \

OBJS_BONUS =		$(addprefix $(BUILD_DIR), $(SRCS_BONUS:.c=.o))

OBJS =				$(addprefix $(BUILD_DIR), $(SRCS:.c=.o))

DEPS =				$(OBJS:.o=.d) \
					$(OBJS_BONUS:.o=.d) \

NAME =				push_swap

LIBFT =				$(LIBFT_DIR)libft.a

# ***************************
# Compilation
# ***************************

FLAGS =				-Wall -Wextra -Werror -g3

DEP_FLAGS =			-MMD -MP

# ***************************
# Commands
# ***************************

MKDIR =			 	mkdir -p

# ***************************
# Rules
# ***************************
.PHONY:				all
all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJS)
					$(CC) $(FLAGS) $(OBJS) -o $@ $(LIBFT)

bonus:				$(LIBFT) $(OBJS_BONUS)
					$(CC) $(FLAGS) $(LIBFT) -I $(INC_DIR) $(OBJS_BONUS) -o checker

-include			$(DEPS)

$(BUILD_DIR)%.o:	$(SRC_DIR)%.c
					mkdir -p $(shell dirname $@)
					$(CC) $(FLAGS) $(DEP_FLAGS) -I $(INC_DIR) -I $(LIBFT_DIR)includes -c $< -o $@

$(LIBFT):			FORCE
					$(MAKE) -j -C $(LIBFT_DIR)

.PHONY:				FORCE
FORCE:

.PHONY:				clean
clean:
					$(RM) $(OBJS) $(OBJS_BONUS) $(DEPS)
					$(MAKE) clean -C $(LIBFT_DIR)

.PHONY:				fclean
fclean:				clean
					$(RM) $(NAME) bonus
					$(MAKE) fclean -C $(LIBFT_DIR)

.PHONY:				re
re:					fclean
					$(MAKE) all
