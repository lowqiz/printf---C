##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile printf
##

NAME	= 		libmy.a 

SRC 	=		src/my_strcat.c    \
				src/my_strlen.c    \
				src/my_getnbr.c    \
				src/my_putchar.c    \
				src/my_put_nbr.c    \
				src/my_putstr.c    \
				src/my_revstr.c    \
				src/send_to.c    \
				src/int_to_str.c	\
				src/my_putnbr_base.c 	\
				src/my_percent_p.c 	\
				src/my_strncat.c 	\
				src/percent_e.c    \
				src/puissance.c    \
				src/percent_g.c    \
				src/send_to2.c    \
				src/send_to3.c    \
				src/my_putnbr_base.c    \
				my_printf.c    \
				src/percent_f.c

OBJ 	= 		$(SRC:.c=.o)

CFLAGS    =    -Wextra -Wall -pedantic -Wshadow -I./ -Wundef -Wpointer-arith -Wfloat-equal -Winit-self -Waggregate-return -Wwrite-strings -Wcast-align -Wmissing-field-initializers

all: 	$(NAME)
 
$(NAME): 		$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: 	fclean all

TESTS := $(wildcard tests/*.c)

test: $(NAME) $(TESTS) my_printf.c
	$(CC) $(CFLAGS) -Iinclude -o tests_run \
		$(TESTS) my_printf.c -L. -lmy -lcriterion
	./tests_run
