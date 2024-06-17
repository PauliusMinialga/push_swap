# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pminialg <pminialg@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/01/25 09:50:49 by pminialg      #+#    #+#                  #
#    Updated: 2024/02/21 10:53:35 by pminialg      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#----------------------------#
NAME = push_swap
BONUS = checker

#----------------------------#
SRCS = $(wildcard src/*.c) 
BONUS_SRCS = $(wildcard checker_src/*.c) src/push.c src/rev_rotate.c src/rotate.c src/swap.c \
	src/init_stack.c src/utils.c src/handle_errors.c

#----------------------------#
OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

#----------------------------#
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

#----------------------------#
all: ${NAME}

${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${OBJS} ./libft/libft.a -o ${NAME}

bonus: ${BONUS}

${BONUS}: ${BONUS_OBJS}
	@${MAKE} -C ./libft
	@${CC} ${BONUS_OBJS} ./libft/libft.a -o ${BONUS}

clean:
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}
	@${RM} ${BONUS_OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${BONUS}

re: fclean bonus all

.PHONY: all bonus clean fclean re