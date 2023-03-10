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

LIST =				lstadd_front_int.c \
					lstadd_back_int.c \
					lst_before_last.c \
					lst_issort_int.c \
					lst_int_rotate.c \
					lst_int_swap.c \
					lst_int_push.c \
					lstclear_int.c \
					lstsize_int.c \
					lstlast_int.c \
					lst_min_max.c \
					lstnew_int.c \
					lst_get_index.c \

SORT =				exception.c \
					bubble_sort.c \
					sort_into_chunk.c \
					calc_operation.c \
					calculate_nb_move.c \
					calculate_best_value.c \


PARSING =			check_number.c \
					calc_index.c \
					parsing.c \
					error.c \

SRCS =				$(addprefix parsing/, $(PARSING)) \
					$(addprefix sort/, $(SORT)) \
					$(addprefix list/, $(LIST)) \
					main.c \

HEADER =			$(addprefix $(INC_DIR), push_swap.h \
											list.h \
											struct.h)

OBJS =				$(addprefix $(BUILD_DIR), $(SRCS:.c=.o))

DEPS =				$(OBJS:.o=.d)

NAME =				push_swap

LIBFT =				$(LIBFT_DIR)libft.a

# ***************************
# Compilation
# ***************************

FLAGS =				-Wall -Wextra -Werror

DEP_FLAGS =			-MMD -MP

# ***************************
# Commands
# ***************************

MKDIR =			 	mkdir -p

# ***************************
# Rules
# ***************************

all:				lib
					$(MAKE) $(NAME)

$(NAME):			$(BUILD_DIR) $(OBJS)
					$(CC) $(FLAGS) -I $(INC_DIR) $(OBJS) -o $@ $(LIBFT)

-include			$(DEPS)

$(BUILD_DIR)%.o:	$(SRC_DIR)%.c
					$(CC) $(FLAGS) $(DEP_FLAGS) -I $(INC_DIR) -c $< -o $@

$(BUILD_DIR):
					$(MKDIR) $(addprefix $(BUILD_DIR), $(DIR))

lib:
					$(MAKE) -j -C $(LIBFT_DIR)

clean:
					$(RM) $(OBJS)
					$(RM) $(DEPS)
					$(MAKE) clean -C $(LIBFT_DIR)

fclean:				clean
					$(RM) $(NAME)
					$(MAKE) fclean -C $(LIBFT_DIR)

re:					fclean
					$(MAKE) all

.PHONY:				all clean fclean re lib
