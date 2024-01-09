# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 15:52:13 by gabe              #+#    #+#              #
#    Updated: 2024/01/09 17:07:08 by gabe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 
SERVER	=	server
CLIENT	=	client

SRC_SERVER	=	server.c utils.c
SRC_CLIENT	=	client.c utils.c

OBJ_SERVER	=	${SRC_SERVER:.c=.o}
OBJ_CLIENT	=	${SRC_CLIENT:.c=.o}

CC			=	cc
RM			=	rm -rf
INCLUDE		=	-I include
CFLAGS		=	-Wall -Werror -Wextra -g
MAKE		=	make -C
LIBFT		=	-L $(LIBFT_PATH) -lft
LIBFT_PATH	=	libft

GREEN		=	\033[38;5;47m
YELLOW		=	\033[38;5;226m
RED			=	\033[38;5;196m
END			=	\033[0m

.c.o:
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}
	@echo "[$(GREEN)compiling$(END)]: $<"

all: ${SERVER} ${CLIENT}

${NAME}: all

${SERVER}: ${OBJ_SERVER}
	@${MAKE} ${LIBFT_PATH}
	@${CC} ${OBJ_SERVER} ${LIBFT} -o ${SERVER}
	@echo "[$(GREEN)compiling$(END)]: $<"

${CLIENT}: ${OBJ_CLIENT}
	@${MAKE} ${LIBFT_PATH}
	@${CC} ${OBJ_CLIENT} ${LIBFT} -o ${CLIENT}
	@echo "[$(GREEN)compiling$(END)]: $<"

clean:
	@${MAKE} ${LIBFT_PATH} clean
	@${RM} ${OBJ_SERVER} ${OBJ_CLIENT}
	@echo "$(RED)cleaning objects$(END)"

fclean: clean
	@${MAKE} ${LIBFT_PATH} fclean
	@${RM} ${SERVER} ${CLIENT}
	@echo "$(RED)$(NAME) deleted$(END)"

re: fclean all