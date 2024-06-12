# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 17:34:16 by anmedyns          #+#    #+#              #
#    Updated: 2024/06/12 20:20:03 by anmedyns         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solong.a

SRCS =

OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} ${HEADER} -Imlx -c $< -o $(<:.c=.o)

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS} ${OBJSBONUS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

git:
	git add .
	git commit -m "update"
	git push
