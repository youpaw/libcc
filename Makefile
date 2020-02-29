# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 15:08:51 by dbutterw          #+#    #+#              #
#    Updated: 2020/01/06 14:39:22 by dbutterw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = char/ft_isalnum.c   \
      char/ft_isalpha.c   \
      char/ft_isascii.c   \
      char/ft_isdigit.c   \
      char/ft_islower.c   \
      char/ft_isprint.c   \
      char/ft_isspace.c   \
      char/ft_isupper.c   \
      char/ft_iswspace.c  \
      char/ft_putchar.c   \
      char/ft_putchar_fd.c  \
      char/ft_tolower.c   \
      char/ft_toupper.c   \
      env/ft_get_env_field.c  \
      env/ft_get_env_fval.c   \
      file/get_next_line.c  \
      list/ft_lstadd.c  \
      list/ft_lstaddsort.c  \
      list/ft_lstcircle.c   \
      list/ft_lstdel.c  \
      list/ft_lstdelcircle.c  \
      list/ft_lstdelone.c   \
      list/ft_lstiter.c   \
      list/ft_lstmap.c  \
      list/ft_lstnew.c  \
      math/ft_max.c   \
      math/ft_min.c   \
      math/ft_pow.c   \
      memory/ft_bzero.c   \
      memory/ft_memalloc.c  \
      memory/ft_memccpy.c   \
      memory/ft_memchr.c  \
      memory/ft_memcmp.c  \
      memory/ft_memcpy.c  \
      memory/ft_memdel.c  \
      memory/ft_memmove.c   \
      memory/ft_memset.c  \
      memory/ft_xmalloc.c \
      num/ft_atoi.c   \
      num/ft_putnbr.c   \
      num/ft_putnbr_fd.c  \
      regex/match.c   \
      regex/nmatch.c  \
      string/ft_itoabase.c  \
      string/ft_itoa.c  \
      string/ft_nstrjoin.c  \
      string/ft_putendl.c   \
      string/ft_putendl_fd.c  \
      string/ft_putstr.c  \
      string/ft_putstr_fd.c   \
      string/ft_strcat.c  \
      string/ft_strchr.c  \
      string/ft_strclr.c  \
      string/ft_strcmp.c  \
      string/ft_strcpy.c  \
      string/ft_strdel.c  \
      string/ft_strdup.c  \
      string/ft_strequ.c  \
      string/ft_striter.c   \
      string/ft_striteri.c  \
      string/ft_strjoin.c   \
      string/ft_strlcat.c   \
      string/ft_strlen.c  \
      string/ft_strmap.c  \
      string/ft_strmapi.c   \
      string/ft_strncat.c   \
      string/ft_strncmp.c   \
      string/ft_strncpy.c   \
      string/ft_strnequ.c   \
      string/ft_strnew.c  \
      string/ft_strnstr.c   \
      string/ft_strrchr.c   \
      string/ft_strsplit.c  \
      string/ft_strstr.c  \
      string/ft_strsub.c  \
      string/ft_strtrim.c   \
      vector/ft_vector_del.c  \
      vector/ft_vector_init.c   \
      vector/ft_vector_push.c   \
      vector/ft_vector_remove.c

INC = -I char		\
      -I env		\
      -I file		\
      -I list		\
      -I math		\
      -I memory		\
      -I num		\
      -I regex		\
      -I string		\
      -I vector

OBJ_DIR = ./obj

CMP_DIR	:= $(OBJ_DIR)/char		\
			$(OBJ_DIR)/env		\
			$(OBJ_DIR)/file		\
			$(OBJ_DIR)/list		\
			$(OBJ_DIR)/math		\
			$(OBJ_DIR)/memory	\
			$(OBJ_DIR)/num		\
			$(OBJ_DIR)/regex	\
			$(OBJ_DIR)/string	\
			$(OBJ_DIR)/vector	\



OBJ	= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

NAME = libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) $(CMP_DIR)

$(OBJ_DIR)/%.o: %.c $(HEAD)
	gcc $(INC) -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all
