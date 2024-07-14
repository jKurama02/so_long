# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 17:34:16 by anmedyns          #+#    #+#              #
#    Updated: 2024/06/24 16:27:16 by anmedyns         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG = so_long

SRCS    =	set_struct.c main.c mapval.c gnl/get_next_line_utils.c gnl/get_next_line.c \
			mapval2.c img.c key_press.c printf/ft_printf.c printf/utili.c printf/utili2.c

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

test-leaks: re
	@clear
	@echo Senza parametri
	-valgrind ./so_long
	@echo
	@echo Piu parametri
	-valgrind ./so_long maps_tester/1.ber maps_tester/2.ber
	@echo
	@echo File inesistente
	-valgrind ./so_long maps_tester/no_exist.ber
	@echo
	@echo File con estenzione non .ber
	-valgrind ./so_long maps_tester/1.aanghi
	@echo
	@echo File vuoto
	-valgrind ./so_long maps_tester/error1.ber
	@echo
	@echo Nessuna uscita nella mappa
	-valgrind ./so_long maps_tester/error2.ber
	@echo
	@echo Nessun collezionabile nella mappa
	-valgrind ./so_long maps_tester/error3.ber
	@echo
	@echo Nessun player nella mappa
	-valgrind ./so_long maps_tester/error4.ber
	@echo
	@echo Carattere estraneo nella mappa
	-valgrind ./so_long maps_tester/error5.ber
	@echo
	@echo Mappa aperta con lo  
	-valgrind ./so_long maps_tester/error6.ber
	@echo
	@echo Mappa aperta con lo 0
	-valgrind ./so_long maps_tester/error7.ber
	@echo
	@echo Mappa incompletabile [Nota se non da errore va bene lo stesso]
	-valgrind ./so_long maps_tester/error8.ber
	@echo
	@echo Mappa quadrata
	-valgrind ./so_long maps_tester/error9.ber
	@echo
	@echo Piu uscite nella mappa
	-valgrind ./so_long maps_tester/error10.ber
	@echo
	@echo Piu player nella mappa
	-valgrind ./so_long maps_tester/error11.ber
	@echo
	@echo Linea vuota nella mappa
	-valgrind ./so_long maps_tester/error12.ber
	@echo
	@echo Mappa incompletabile, uscita irraggiungibile
	-valgrind ./so_long maps_tester/error13.ber
	@echo
	@echo Mappa incompletabile, moneta irraggiungibile
	-valgrind ./so_long maps_tester/error14.ber
	@echo
	@echo Righe vuote sopra la mappa
	-valgrind ./so_long maps_tester/error15.ber
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-nleaks: re
	@clear
	@echo Senza parametri
	-./so_long
	@echo
	@echo Piu parametri
	-./so_long maps_tester/1.ber maps_tester/2.ber
	@echo
	@echo File inesistente
	-./so_long maps_tester/no_exist.ber
	@echo
	@echo File con estenzione non .ber
	-./so_long maps_tester/1.aanghi
	@echo
	@echo File vuoto
	-./so_long maps_tester/error1.ber
	@echo
	@echo Nessuna uscita nella mappa
	-./so_long maps_tester/error2.ber
	@echo
	@echo Nessun collezionabile nella mappa
	-./so_long maps_tester/error3.ber
	@echo
	@echo Nessun player nella mappa
	-./so_long maps_tester/error4.ber
	@echo
	@echo Carattere estraneo nella mappa
	-./so_long maps_tester/error5.ber
	@echo
	@echo Mappa aperta con lo  
	-./so_long maps_tester/error6.ber
	@echo
	@echo Mappa aperta con lo 0
	-./so_long maps_tester/error7.ber
	@echo
	@echo Mappa incompletabile [Nota se non da errore va bene lo stesso]
	-./so_long maps_tester/error8.ber
	@echo
	@echo Mappa quadrata
	-./so_long maps_tester/error9.ber
	@echo
	@echo Piu uscite nella mappa
	-./so_long maps_tester/error10.ber
	@echo
	@echo Piu player nella mappa
	-./so_long maps_tester/error11.ber
	@echo
	@echo Linea vuota nella mappa
	-./so_long maps_tester/error12.ber
	@echo
	@echo Mappa incompletabile, uscita irraggiungibile
	-./so_long maps_tester/error13.ber
	@echo
	@echo Mappa incompletabile, moneta irraggiungibile
	-./so_long maps_tester/error14.ber
	@echo
	@echo Righe vuote sopra la mappa
	-./so_long maps_tester/error15.ber
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-norm:
	@echo Errori di norma:
	@norminette *.c *.h | grep Error! | wc -l
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]


test-leaks: re
	@clear
	@echo Senza parametri
	-valgrind ./so_long
	@echo
	@echo Piu parametri
	-valgrind ./so_long maps_tester/1.ber maps_tester/2.ber
	@echo
	@echo File inesistente
	-valgrind ./so_long maps_tester/no_exist.ber
	@echo
	@echo File con estenzione non .ber
	-valgrind ./so_long maps_tester/1.aanghi
	@echo
	@echo File vuoto
	-valgrind ./so_long maps_tester/error1.ber
	@echo
	@echo Nessuna uscita nella mappa
	-valgrind ./so_long maps_tester/error2.ber
	@echo
	@echo Nessun collezionabile nella mappa
	-valgrind ./so_long maps_tester/error3.ber
	@echo
	@echo Nessun player nella mappa
	-valgrind ./so_long maps_tester/error4.ber
	@echo
	@echo Carattere estraneo nella mappa
	-valgrind ./so_long maps_tester/error5.ber
	@echo
	@echo Mappa aperta con lo  
	-valgrind ./so_long maps_tester/error6.ber
	@echo
	@echo Mappa aperta con lo 0
	-valgrind ./so_long maps_tester/error7.ber
	@echo
	@echo Mappa incompletabile [Nota se non da errore va bene lo stesso]
	-valgrind ./so_long maps_tester/error8.ber
	@echo
	@echo Mappa quadrata
	-valgrind ./so_long maps_tester/error9.ber
	@echo
	@echo Piu uscite nella mappa
	-valgrind ./so_long maps_tester/error10.ber
	@echo
	@echo Piu player nella mappa
	-valgrind ./so_long maps_tester/error11.ber
	@echo
	@echo Linea vuota nella mappa
	-valgrind ./so_long maps_tester/error12.ber
	@echo
	@echo Mappa incompletabile, uscita irraggiungibile
	-valgrind ./so_long maps_tester/error13.ber
	@echo
	@echo Mappa incompletabile, moneta irraggiungibile
	-valgrind ./so_long maps_tester/error14.ber
	@echo
	@echo Righe vuote sopra la mappa
	-valgrind ./so_long maps_tester/error15.ber
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-nleaks: re
	@clear
	@echo Senza parametri
	-./so_long
	@echo
	@echo Piu parametri
	-./so_long maps_tester/1.ber maps_tester/2.ber
	@echo
	@echo File inesistente
	-./so_long maps_tester/no_exist.ber
	@echo
	@echo File con estenzione non .ber
	-./so_long maps_tester/1.aanghi
	@echo
	@echo File vuoto
	-./so_long maps_tester/error1.ber
	@echo
	@echo Nessuna uscita nella mappa
	-./so_long maps_tester/error2.ber
	@echo
	@echo Nessun collezionabile nella mappa
	-./so_long maps_tester/error3.ber
	@echo
	@echo Nessun player nella mappa
	-./so_long maps_tester/error4.ber
	@echo
	@echo Carattere estraneo nella mappa
	-./so_long maps_tester/error5.ber
	@echo
	@echo Mappa aperta con lo  
	-./so_long maps_tester/error6.ber
	@echo
	@echo Mappa aperta con lo 0
	-./so_long maps_tester/error7.ber
	@echo
	@echo Mappa incompletabile [Nota se non da errore va bene lo stesso]
	-./so_long maps_tester/error8.ber
	@echo
	@echo Mappa quadrata
	-./so_long maps_tester/error9.ber
	@echo
	@echo Piu uscite nella mappa
	-./so_long maps_tester/error10.ber
	@echo
	@echo Piu player nella mappa
	-./so_long maps_tester/error11.ber
	@echo
	@echo Linea vuota nella mappa
	-./so_long maps_tester/error12.ber
	@echo
	@echo Mappa incompletabile, uscita irraggiungibile
	-./so_long maps_tester/error13.ber
	@echo
	@echo Mappa incompletabile, moneta irraggiungibile
	-./so_long maps_tester/error14.ber
	@echo
	@echo Righe vuote sopra la mappa
	-./so_long maps_tester/error15.ber
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-norm:
	@echo Errori di norma:
	@norminette *.c *.h | grep Error! | wc -l
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]


test-leaks: re
	@clear
	@echo Senza parametri
	-valgrind ./so_long
	@echo
	@echo Piu parametri
	-valgrind ./so_long maps_tester/1.ber maps_tester/2.ber
	@echo
	@echo File inesistente
	-valgrind ./so_long maps_tester/no_exist.ber
	@echo
	@echo File con estenzione non .ber
	-valgrind ./so_long maps_tester/1.aanghi
	@echo
	@echo File vuoto
	-valgrind ./so_long maps_tester/error1.ber
	@echo
	@echo Nessuna uscita nella mappa
	-valgrind ./so_long maps_tester/error2.ber
	@echo
	@echo Nessun collezionabile nella mappa
	-valgrind ./so_long maps_tester/error3.ber
	@echo
	@echo Nessun player nella mappa
	-valgrind ./so_long maps_tester/error4.ber
	@echo
	@echo Carattere estraneo nella mappa
	-valgrind ./so_long maps_tester/error5.ber
	@echo
	@echo Mappa aperta con lo  
	-valgrind ./so_long maps_tester/error6.ber
	@echo
	@echo Mappa aperta con lo 0
	-valgrind ./so_long maps_tester/error7.ber
	@echo
	@echo Mappa incompletabile [Nota se non da errore va bene lo stesso]
	-valgrind ./so_long maps_tester/error8.ber
	@echo
	@echo Mappa quadrata
	-valgrind ./so_long maps_tester/error9.ber
	@echo
	@echo Piu uscite nella mappa
	-valgrind ./so_long maps_tester/error10.ber
	@echo
	@echo Piu player nella mappa
	-valgrind ./so_long maps_tester/error11.ber
	@echo
	@echo Linea vuota nella mappa
	-valgrind ./so_long maps_tester/error12.ber
	@echo
	@echo Mappa incompletabile, uscita irraggiungibile
	-valgrind ./so_long maps_tester/error13.ber
	@echo
	@echo Mappa incompletabile, moneta irraggiungibile
	-valgrind ./so_long maps_tester/error14.ber
	@echo
	@echo Righe vuote sopra la mappa
	-valgrind ./so_long maps_tester/error15.ber
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-nleaks: re
	@clear
	@echo Senza parametri
	-./so_long
	@echo
	@echo Piu parametri
	-./so_long maps_tester/1.ber maps_tester/2.ber
	@echo
	@echo File inesistente
	-./so_long maps_tester/no_exist.ber
	@echo
	@echo File con estenzione non .ber
	-./so_long maps_tester/1.aanghi
	@echo
	@echo File vuoto
	-./so_long maps_tester/error1.ber
	@echo
	@echo Nessuna uscita nella mappa
	-./so_long maps_tester/error2.ber
	@echo
	@echo Nessun collezionabile nella mappa
	-./so_long maps_tester/error3.ber
	@echo
	@echo Nessun player nella mappa
	-./so_long maps_tester/error4.ber
	@echo
	@echo Carattere estraneo nella mappa
	-./so_long maps_tester/error5.ber
	@echo
	@echo Mappa aperta con lo  
	-./so_long maps_tester/error6.ber
	@echo
	@echo Mappa aperta con lo 0
	-./so_long maps_tester/error7.ber
	@echo
	@echo Mappa incompletabile [Nota se non da errore va bene lo stesso]
	-./so_long maps_tester/error8.ber
	@echo
	@echo Mappa quadrata
	-./so_long maps_tester/error9.ber
	@echo
	@echo Piu uscite nella mappa
	-./so_long maps_tester/error10.ber
	@echo
	@echo Piu player nella mappa
	-./so_long maps_tester/error11.ber
	@echo
	@echo Linea vuota nella mappa
	-./so_long maps_tester/error12.ber
	@echo
	@echo Mappa incompletabile, uscita irraggiungibile
	-./so_long maps_tester/error13.ber
	@echo
	@echo Mappa incompletabile, moneta irraggiungibile
	-./so_long maps_tester/error14.ber
	@echo
	@echo Righe vuote sopra la mappa
	-./so_long maps_tester/error15.ber
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-norm:
	@echo Errori di norma:
	@norminette *.c *.h | grep Error! | wc -l
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]


test-leaks: re
	@clear
	@echo Senza parametri
	-valgrind ./so_long
	@echo
	@echo Piu parametri
	-valgrind ./so_long maps_tester/1.ber maps_tester/2.ber
	@echo
	@echo File inesistente
	-valgrind ./so_long maps_tester/no_exist.ber
	@echo
	@echo File con estenzione non .ber
	-valgrind ./so_long maps_tester/1.aanghi
	@echo
	@echo File vuoto
	-valgrind ./so_long maps_tester/error1.ber
	@echo
	@echo Nessuna uscita nella mappa
	-valgrind ./so_long maps_tester/error2.ber
	@echo
	@echo Nessun collezionabile nella mappa
	-valgrind ./so_long maps_tester/error3.ber
	@echo
	@echo Nessun player nella mappa
	-valgrind ./so_long maps_tester/error4.ber
	@echo
	@echo Carattere estraneo nella mappa
	-valgrind ./so_long maps_tester/error5.ber
	@echo
	@echo Mappa aperta con lo  
	-valgrind ./so_long maps_tester/error6.ber
	@echo
	@echo Mappa aperta con lo 0
	-valgrind ./so_long maps_tester/error7.ber
	@echo
	@echo Mappa incompletabile [Nota se non da errore va bene lo stesso]
	-valgrind ./so_long maps_tester/error8.ber
	@echo
	@echo Mappa quadrata
	-valgrind ./so_long maps_tester/error9.ber
	@echo
	@echo Piu uscite nella mappa
	-valgrind ./so_long maps_tester/error10.ber
	@echo
	@echo Piu player nella mappa
	-valgrind ./so_long maps_tester/error11.ber
	@echo
	@echo Linea vuota nella mappa
	-valgrind ./so_long maps_tester/error12.ber
	@echo
	@echo Mappa incompletabile, uscita irraggiungibile
	-valgrind ./so_long maps_tester/error13.ber
	@echo
	@echo Mappa incompletabile, moneta irraggiungibile
	-valgrind ./so_long maps_tester/error14.ber
	@echo
	@echo Righe vuote sopra la mappa
	-valgrind ./so_long maps_tester/error15.ber
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-nleaks: re
	@clear
	@echo Senza parametri
	-./so_long
	@echo
	@echo Piu parametri
	-./so_long maps_tester/1.ber maps_tester/2.ber
	@echo
	@echo File inesistente
	-./so_long maps_tester/no_exist.ber
	@echo
	@echo File con estenzione non .ber
	-./so_long maps_tester/1.aanghi
	@echo
	@echo File vuoto
	-./so_long maps_tester/error1.ber
	@echo
	@echo Nessuna uscita nella mappa
	-./so_long maps_tester/error2.ber
	@echo
	@echo Nessun collezionabile nella mappa
	-./so_long maps_tester/error3.ber
	@echo
	@echo Nessun player nella mappa
	-./so_long maps_tester/error4.ber
	@echo
	@echo Carattere estraneo nella mappa
	-./so_long maps_tester/error5.ber
	@echo
	@echo Mappa aperta con lo  
	-./so_long maps_tester/error6.ber
	@echo
	@echo Mappa aperta con lo 0
	-./so_long maps_tester/error7.ber
	@echo
	@echo Mappa incompletabile [Nota se non da errore va bene lo stesso]
	-./so_long maps_tester/error8.ber
	@echo
	@echo Mappa quadrata
	-./so_long maps_tester/error9.ber
	@echo
	@echo Piu uscite nella mappa
	-./so_long maps_tester/error10.ber
	@echo
	@echo Piu player nella mappa
	-./so_long maps_tester/error11.ber
	@echo
	@echo Linea vuota nella mappa
	-./so_long maps_tester/error12.ber
	@echo
	@echo Mappa incompletabile, uscita irraggiungibile
	-./so_long maps_tester/error13.ber
	@echo
	@echo Mappa incompletabile, moneta irraggiungibile
	-./so_long maps_tester/error14.ber
	@echo
	@echo Righe vuote sopra la mappa
	-./so_long maps_tester/error15.ber
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-norm:
	@echo Errori di norma:
	@norminette *.c *.h | grep Error! | wc -l
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

