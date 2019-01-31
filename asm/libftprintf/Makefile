NAME = libftprintf.a

CC = gcc
RM = /bin/rm -rf

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/
SRC := src/ft_helpers/ft_atoi.c src/ft_helpers/ft_bzero.c src/ft_helpers/ft_isalnum.c src/ft_helpers/ft_isalpha.c \
		src/ft_helpers/ft_isascii.c src/ft_helpers/ft_isdigit.c src/ft_helpers/ft_isprint.c src/ft_helpers/ft_tolower.c \
		src/ft_helpers/ft_itoa.c src/ft_helpers/ft_max_in_array.c src/ft_helpers/ft_pow.c src/ft_helpers/ft_read_from_fd.c \
		src/ft_helpers/ft_sort_int.c src/ft_helpers/ft_sqrt.c src/ft_helpers/get_next_line.c src/ft_helpers/ft_toupper.c \
		src/ft_lst/ft_lst_size.c src/ft_lst/ft_lstadd_back.c src/ft_lst/ft_lstadd.c src/ft_lst/ft_lstdel.c \
		src/ft_lst/ft_lstdelone.c src/ft_lst/ft_lstiter.c src/ft_lst/ft_lstmap.c src/ft_lst/ft_lstnew.c \
		src/ft_mem/ft_memalloc.c src/ft_mem/ft_memccpy.c src/ft_mem/ft_memchr.c src/ft_mem/ft_memcmp.c src/ft_mem/ft_memcpy.c \
		src/ft_mem/ft_memdel.c src/ft_mem/ft_memmove.c src/ft_mem/ft_memset.c \
		src/ft_printf/ft_array_of_specifiers.c src/ft_printf/ft_handle_flag_length.c src/ft_printf/ft_handle_flags.c \
		src/ft_printf/ft_helpers.c src/ft_printf/ft_printf.c src/ft_printf/ft_string_from_num.c src/ft_printf/ft_write_string.c \
		src/ft_printf/ft_length/ft_length_h.c src/ft_printf/ft_length/ft_length_hh.c src/ft_printf/ft_length/ft_length_j.c \
		src/ft_printf/ft_length/ft_length_l.c src/ft_printf/ft_length/ft_length_ll.c src/ft_printf/ft_length/ft_length_z.c \
		src/ft_printf/ft_length/ft_length_none_numbers.c src/ft_printf/ft_length/ft_length_none.c \
		src/ft_put/ft_putchar_fd.c src/ft_put/ft_putchar.c src/ft_put/ft_putendl_fd.c src/ft_put/ft_putendl.c \
		src/ft_put/ft_putnbr_fd.c src/ft_put/ft_putnbr.c src/ft_put/ft_putstr_fd.c src/ft_put/ft_putstr.c \
		src/ft_str/ft_str_to_upper.c src/ft_str/ft_str_tolower.c src/ft_str/ft_str_unsigned_concat.c \
		src/ft_str/ft_str_unsigned_del.c src/ft_str/ft_str_unsigned_new.c src/ft_str/ft_strcat.c src/ft_str/ft_strchr.c \
		src/ft_str/ft_strclr.c src/ft_str/ft_strcmp.c src/ft_str/ft_strconcat.c src/ft_str/ft_strcpy.c src/ft_str/ft_strdel.c \
		src/ft_str/ft_strdup_until.c src/ft_str/ft_strdup.c src/ft_str/ft_strequ.c src/ft_str/ft_striter.c \
		src/ft_str/ft_striteri.c src/ft_str/ft_strjoin.c src/ft_str/ft_strlcat.c src/ft_str/ft_strlen.c src/ft_str/ft_strmap.c \
		src/ft_str/ft_strmapi.c src/ft_str/ft_strncat.c src/ft_str/ft_strncmp.c src/ft_str/ft_strncpy.c src/ft_str/ft_strnequ.c \
		src/ft_str/ft_strnew.c src/ft_str/ft_strnstr.c src/ft_str/ft_strrchr.c src/ft_str/ft_strsplit.c src/ft_str/ft_strstr.c \
		src/ft_str/ft_strsub.c src/ft_str/ft_strtrim.c
# SRC := src/ft_helpers/*.c src/ft_lst/*.c src/ft_mem/*.c src/ft_printf/*.c src/ft_put/*.c src/ft_str/*.c



OBJ = $(addprefix $(OBJ_DIR), $(SRC:src/%.c=%.o))

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(INC_DIR)*
	 ar rc $(NAME) $(OBJ)
	 ranlib $(NAME)
$(OBJ_DIR)%.o : %.c
	mkdir -p obj
	mkdir -p obj/ft_helpers
	mkdir -p obj/ft_lst
	mkdir -p obj/ft_mem
	mkdir -p obj/ft_printf
	mkdir -p obj/ft_put
	mkdir -p obj/ft_str
	mkdir -p obj/ft_printf/ft_length
	gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR)

clean:
	$(RM) $(OBJ_DIR)
fclean: clean
	$(RM) $(NAME)
re: fclean all

vpath %.c $(SRC_DIR) 