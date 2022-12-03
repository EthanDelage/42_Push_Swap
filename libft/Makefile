# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 14:38:11 by edelage           #+#    #+#              #
#    Updated: 2022/11/28 03:09:58 by edelage          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ***************************
#  Folders
# ***************************

INC_DIR =		includes/

SRC_DIR =		srcs/

OBJ_DIR =		.objs/

DIR =			char \
				convert \
				fd \
				get_next_line \
				list \
				memory \
				string \

# ***************************
#  Files
# ***************************

CHAR =			ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_isspace.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_issign.c \

CONVERT =		ft_atoi.c \
				ft_itoa.c \

FD =			ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \

GNL =			get_next_line.c \
				get_next_line_utils.c \

LST =			ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \

MEMORY =		ft_memset.c \
				ft_memchr.c \
				ft_memcpy.c \
				ft_memcmp.c \
				ft_memmove.c \
				ft_bzero.c \
				ft_calloc.c \

STRING =		ft_strlen.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_strmapi.c \
				ft_striteri.c \

SRCS =			$(addprefix fd/, $(FD)) \
				$(addprefix char/, $(CHAR)) \
				$(addprefix list/, $(LST)) \
				$(addprefix memory/, $(MEMORY)) \
				$(addprefix string/, $(STRING)) \
				$(addprefix convert/, $(CONVERT)) \
				$(addprefix get_next_line/, $(GNL)) \

HEADER =		$(INC_DIR)libft.h \
				$(INC_DIR)get_next_line.h \

OBJS =			$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

DEPS =			$(OBJS:.o=.d)

NAME =			libft.a

# ***************************
# Compilation
# ***************************

FLAGS =			-Wall -Wextra -Werror

DEP_FLAGS =		-MMD -MP

# ***************************
# Commands
# ***************************

AR_FLAGS =		rcs

MKDIR =			mkdir -p

# ***************************
# Rules
# ***************************

all:			$(NAME)

$(NAME):		$(OBJ_DIR) $(OBJS)
				$(AR) $(AR_FLAGS) $@ $(OBJS)

-include		$(DEPS)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c Makefile
				$(CC) $(FLAGS) $(DEP_FLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR):
				$(MKDIR) $(addprefix $(OBJ_DIR), $(DIR))

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean
				$(MAKE) all

.PHONY:			all clean fclean re
