##
##  EPITECH PROJECT, 2021 
##  MakeFile
##  File description
##  Make my lib
##

CC	=	gcc
FLAGS	=	-W -Wall -Wextra -Werror

LIB_SRC		=	my_compute_power_rec.c \
			my_getnbr.c \
			my_min_array.c \
			my_put_nbr.c \
			my_showmem.c \
			my_strcapitalize.c \
			my_strcpy.c \
			my_str_islower.c \
			my_str_isupper.c \
			my_strncat.c \
			my_strstr.c \
			my_swap.c \
			my_compute_square_root.c \
			my_isneg.c \
			my_putchar.c \
			my_putstr.c \
			my_showstr.c \
			my_strcat.c \
			my_strdup.c \
			my_str_isnum.c \
			my_strlen.c \
			my_strncmp.c \
			my_str_to_word_array.c \
			my_find_prime_sup.c \
			my_is_prime.c \
			my_putnbr_base.c \
			my_revstr.c \
			my_sort_int_array.c \
			my_strcmp.c \
			my_str_isalpha.c \
			my_str_isprintable.c \
			my_strlowcase.c \
			my_strncpy.c \
			my_strupcase.c \
			my_max.c \
			my_min.c \
			my_abs.c \
			my_strswap.c \
			my_calloc.c \
			my_putchar_err.c \
			my_putstr_err.c

LIB_OBJ		=	my_compute_power_rec.o \
			my_getnbr.o \
			my_min_array.o \
			my_put_nbr.o \
			my_showmem.o \
			my_strcapitalize.o \
			my_strcpy.o \
			my_str_islower.o \
			my_str_isupper.o \
			my_strncat.o \
			my_strstr.o \
			my_swap.o \
			my_compute_square_root.o \
			my_isneg.o \
			my_putchar.o \
			my_putstr.o \
			my_showstr.o \
			my_strcat.o \
			my_strdup.o \
			my_str_isnum.o \
			my_strlen.o \
			my_strncmp.o \
			my_str_to_word_array.o \
			my_find_prime_sup.o \
			my_is_prime.o \
			my_putnbr_base.o \
			my_revstr.o \
			my_sort_int_array.o \
			my_strcmp.o \
			my_str_isalpha.o \
			my_str_isprintable.o \
			my_strlowcase.o \
			my_strncpy.o \
			my_strupcase.o \
			my_max.o \
			my_min.o \
			my_abs.o \
			my_strswap.o \
			my_calloc.o \
			my_putchar_err.o \
			my_putstr_err.o

TARGET_LIB	=	libmy.a

$(TARGET_LIB):
	mkdir -p ../../include
	cp my.h ../../include
	$(CC) -c $(LIB_SRC)
	ar src $(TARGET_LIB) $(LIB_OBJ)
	cp libmy.a ../

clean:
	rm -rf $(TARGET_LIB)
	rm -rf $(LIB_OBJ)

fclean: clean
	rm ../libmy.a

re:	fclean all
