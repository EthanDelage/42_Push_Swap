# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 11:49:53 by edelage           #+#    #+#              #
#    Updated: 2022/12/01 18:58:16 by edelage          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ***************************
#  Folders
# ***************************

INC_DIR =		includes/

SRC_DIR =		srcs/

OBJ_DIR =		.objs/

DIR =			parsing/ \
				sort/ \
				list/ \

LIBFT_DIR =		libft/

# ***************************
#  Files
# ***************************

LIST =			lstadd_front_int.c \
				lst_before_last.c \
				lst_display_int.c \
				lstadd_back_int.c \
				lst_search_int.c \
				lst_issort_int.c \
				lst_int_rotate.c \
				lst_index_int.c \
				lst_int_swap.c \
				lst_int_push.c \
				lstclear_int.c \
				lstsize_int.c \
				lstlast_int.c \
				lstnew_int.c \

SORT =			bubble_sort.c \
				calc_operation.c \


PARSING =		check_number.c \
				calc_index.c \
				parsing.c \
				error.c \

SRCS =			$(addprefix parsing/, $(PARSING)) \
				$(addprefix sort/, $(SORT)) \
				$(addprefix list/, $(LIST)) \
				main.c \

HEADER =		$(addprefix $(INC_DIR), push_swap.h \
										list.h \
										struct.h)

OBJS =			$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

DEPS =			$(OBJS:.o=.d)

NAME =			push_swap

LIBFT =			$(LIBFT_DIR)libft.a

# ***************************
# Compilation
# ***************************

FLAGS =			-Wall -Wextra -Werror -g

DEP_FLAGS =		-MMD -MP

# ***************************
# Commands
# ***************************

MKDIR =			mkdir -p

# ***************************
# Rules
# ***************************

all:			lib
				$(MAKE) $(NAME)

$(NAME):		$(OBJ_DIR) $(OBJS)
				$(CC) $(FLAGS) -I $(INC_DIR) $(OBJS) -o $@ $(LIBFT)

-include		$(DEPS)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				$(CC) $(FLAGS) $(DEP_FLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR):
				$(MKDIR) $(addprefix $(OBJ_DIR), $(DIR))

lib:
				$(MAKE) -j -C $(LIBFT_DIR)

clean:
				$(RM) $(OBJS)
				$(RM) $(DEPS)
				$(MAKE) clean -C $(LIBFT_DIR)

fclean:			clean
				$(RM) $(NAME)
				$(MAKE) fclean -C $(LIBFT_DIR)

re:				fclean
				$(MAKE) all

.PHONY:			all clean fclean re lib
