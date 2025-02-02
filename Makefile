# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 15:26:50 by jtinaut-          #+#    #+#              #
#    Updated: 2024/10/30 16:56:17 by jtinaut-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror -g
LIBFTDIR = libft/
OBJ_DIR = obj/

SRC = src/list_indexator.c src/order-0.c src/order-3.c src/solver-0.c src/solver-3.c\
	  src/list_utils.c src/order-1.c src/parser.c src/solver-1.c src/solver_utils.c\
	  src/little_solver.c src/order-2.c src/push_swap.c src/solver-2.c src/utils.c

OBJ = ${SRC:.c=.o}

INCLUDE = -L ./libft -lft

%.o: %.c Makefile includes/push_swap.h libft/libft.a
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all: make_libs ${NAME}

make_libs:
	make -C $(LIBFTDIR)

${NAME}: ${OBJ}
			${CC} ${FLAGS} ${OBJ} -o ${NAME} ${INCLUDE}

clean:
		${RM} ${OBJ}
		@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
		${RM} ${NAME}
		@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re
