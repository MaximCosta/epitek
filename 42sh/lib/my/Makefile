##
## EPITECH PROJECT, 2021
## B-CPE-100-MPL-1-1-cpoolday10-kilyan.cotten
## File description:
## Makefile
##

CC    = gcc
CFLAGS    = -W -Wall -Wextra -Werror

LIB_SRC     =   my_strcmp.c \
				my_strdup.c \
				my_swap.c \
				lib_tests.c \
				my_str_isupper.c \
				my_strncmp.c \
				my_is_prime.c \
				my_showmem.c \
				my_getnbr_base2.c \
				my_str_isprintable.c \
				my_show_word_array.c \
				my_revstr.c \
				my_strlowcase.c \
				my_strcpy.c \
				my_strstr.c \
				my_strupcase.c \
				my_strlen.c \
				my_strncpy.c \
				my_putnbr_base.c \
				my_isneg.c \
				my_putchar.c \
				my_put_nbr.c \
				my_putstr.c \
				my_compute_square_root.c \
				my_strncat.c \
				my_getnbr2.c \
				my_str_to_word_array.c \
				my_getnbr.c \
				my_strcat.c \
				my_find_prime_sup.c \
				my_str_isalpha.c \
				my_str_islower.c \
				my_showstr.c \
				my_str_isnum.c \
				my_sort_int_array.c \
				my_compute_power_rec.c \
				my_strcapitalize.c \
				my_getnbr_base.c \
				str_ndup.c \
				my_calloc.c \

LIB_OBJ     =   my_strcmp.o \
				my_strdup.o \
				my_swap.o \
				lib_tests.o \
				my_str_isupper.o \
				my_strncmp.o \
				my_is_prime.o \
				my_showmem.o \
				my_getnbr_base2.o \
				my_str_isprintable.o \
				my_show_word_array.o \
				my_revstr.o \
				my_strlowcase.o \
				my_strcpy.o \
				my_strstr.o \
				my_strupcase.o \
				my_strlen.o \
				my_strncpy.o \
				my_putnbr_base.o \
				my_isneg.o \
				my_putchar.o \
				my_put_nbr.o \
				my_putstr.o \
				my_compute_square_root.o \
				my_strncat.o \
				my_getnbr2.o \
				my_str_to_word_array.o \
				my_getnbr.o \
				my_strcat.o \
				my_find_prime_sup.o \
				my_str_isalpha.o \
				my_str_islower.o \
				my_showstr.o \
				my_str_isnum.o \
				my_sort_int_array.o \
				my_compute_power_rec.o \
				my_strcapitalize.o \
				my_getnbr_base.o \
				str_ndup.o \
				my_calloc.o \

TARGET_LIB    =     libmy.a

all: $(TARGET_LIB)

$(TARGET_LIB): $(LIB_OBJ)
	@ ar src $(TARGET_LIB) $(LIB_OBJ)
	@ cp $(TARGET_LIB) ..

$(LIB_OBJ): $(LIB_SRC)
	@ $(CC) $(CFLAGS) -c $(LIB_SRC)

clean :
	@ rm -rf $(TARGET_LIB)
	@ rm -rf $(LIB_OBJ)
	@ rm -rf $(OBJ)

fclean : clean
	@ rm -rf ../$(TARGET_LIB)
