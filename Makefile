# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 17:34:16 by anmedyns          #+#    #+#              #
#    Updated: 2024/06/23 18:37:10 by anmedyns         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG = so_long

SRCS    =	set_struct.c mapval.c main.c gnl/get_next_line_utils.c gnl/get_next_line.c \
			mapval2.c img.c key_press.c

OBJS     = ${SRCS:.c=.o}
MAIN    = main.c

HEADER    = -Iinclude

CC         = gcc
CFLAGS     = -Wall -Wextra -Werror -g

.c.o:        %.o : %.c
	@gcc ${CFLAGS} ${HEADER} -Imlx -c $< -o $(<:.c=.o)

all:         ${PROG}

${PROG}:    ${OBJS}
						@echo "\033[33m----Compiling lib----"
						@$(CC) ${OBJS} -lmlx -lXext -lX11 -L mlx -o${PROG} printf/libftprintf.a
						@echo "\033[32mSo Long Compiled!\n	"

clean:
						@rm -f ${OBJS}


fclean:     clean
						@rm -f $(NAME)
						@rm -f ${PROG}
						@echo "\n\033[31mDeleting EVERYTHING!\n"

git:
	git add .
	git commit -m "update"
	git push

re:            fclean all

.PHONY: all clean fclean re
