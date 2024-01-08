# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 10:18:50 by gamoreir          #+#    #+#              #
#    Updated: 2023/11/16 18:24:53 by gabe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
INCLUDE = .
RM = rm -f
AR = ar -rc
NAME = libft.a

OBJ = ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_strlen.o ft_memset.o ft_bzero.o ft_memmove.o ft_memcpy.o \
      ft_strlcpy.o ft_toupper.o ft_tolower.o ft_strchr.o ft_strrchr.o ft_strncmp.o ft_memchr.o ft_memcmp.o ft_strnstr.o ft_atoi.o \
      ft_calloc.o ft_strdup.o ft_strmapi.o ft_substr.o ft_strlcat.o ft_strjoin.o ft_strtrim.o ft_split.o ft_itoa.o ft_putchar_fd.o \
      ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_striteri.o ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o \
      ft_lstclear.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o ft_printf.o ft_printf_functions.o get_next_line.o

GREEN		= \033[38;5;47m
YELLOW		= \033[38;5;226m
RED			= \033[38;5;196m
END 		= \033[0m

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDE)
	@echo "[$(GREEN)compiling$(END)]: $<"

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $^
	@echo "$(GREEN)libft created$(END)"

clean:
	@$(RM) $(OBJ)
	@echo "$(RED)cleaning objects$(END)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) deleted$(END)"

re: fclean all