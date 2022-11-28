# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 11:49:53 by edelage           #+#    #+#              #
#    Updated: 2022/11/28 18:31:10 by edelage          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ***************************
#  Folders
# ***************************

INC_DIR =		includes/

SRC_DIR =		srcs/

OBJ_DIR =		.objs/

DIR =			parsing/ \
				list/ \

LIBFT_DIR =		libft/

# ***************************
#  Files
# ***************************

LIST =			lstadd_front_int.c \
				lst_display_int.c \
				lstadd_back_int.c \
				lst_issort_int.c \
				lstclear_int.c \
				lstnew_int.c \

PARSING =		check_number.c \
				parsing.c \
				error.c \

SRCS =			$(addprefix parsing/, $(PARSING)) \
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

FLAGS =			-Wall -Wextra -Werror

DEP_FLAGS =		-MMD -MP

# ***************************
# Commands
# ***************************

MKDIR =			mkdir -p

# ***************************
# Rules
# ***************************

all:			lib
				$(MAKE) -j $(NAME)

$(NAME):		$(OBJ_DIR) $(OBJS)
				$(CC) $(FLAGS) -I $(INC_DIR) $(OBJS) -o $@ $(LIBFT)

-include		$(DEPS)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c Makefile
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
