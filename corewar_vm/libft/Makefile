NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3

RM = /bin/rm -rf

SRC_DIR = ./src/
INC_DIR = ./inc/
OBJ_DIR = ./obj/

FT_PRINTF_SRC_DIR = ft_printf/
FT_PRINTF_INC_DIR = $(INC_DIR)ft_printf/
FT_PRINTF_OBJ_DIR = $(OBJ_DIR)ft_printf/
LIBFT_SRC = \
ft_printf/ft_printf_parsers.c \
ft_printf/fpf_manage_number.c \
ft_printf/ft_printf_core.c \
ft_printf/ft_printf.c \
ft_printf/fpf_manage_char.c \
ft_printf/ft_printf_utils.c \
ft_printf/ft_printf_printers.c \
ft_printf/fpf_manage_string.c \
get_next_line/get_next_line.c \
printers/ft_putnbr_fd.c \
printers/ft_putendl.c \
printers/ft_putchar.c \
printers/ft_putnbr.c \
printers/ft_perror.c \
printers/ft_putstr.c \
printers/ft_putendl_fd.c \
printers/ft_putchar_fd.c \
printers/ft_putstr_fd.c \
num/ft_itoa_base.c \
num/ft_count_words.c \
num/ft_atoi_base.c \
num/ft_numlen.c \
num/ft_atoi.c \
num/ft_itoa.c \
btree/btree_level_count.c \
btree/btree_search_data.c \
btree/btree_delone.c \
btree/btree_insert_data.c \
btree/btree_print.c \
btree/btree_dfs_preorder.c \
btree/btree_dfs_inorder.c \
btree/btree_dfs_postorder.c \
btree/btree_create_node.c \
btree/btree_del.c \
stack/stack_push.c \
stack/stack_peek.c \
stack/stack_pop.c \
str/ft_str_toupper.c \
str/ft_strnew.c \
str/ft_strclr.c \
str/ft_strlen.c \
str/ft_strtrim.c \
str/ft_strdup.c \
str/ft_strrchr.c \
str/ft_strequ.c \
str/ft_strmapi.c \
str/ft_striteri.c \
str/ft_strnequ.c \
str/ft_strncmp.c \
str/ft_strlcat.c \
str/ft_strcat.c \
str/ft_strncpy.c \
str/ft_strdel.c \
str/ft_strchr.c \
str/ft_strjoin.c \
str/ft_strrev.c \
str/ft_striter.c \
str/ft_strmap.c \
str/ft_strsub.c \
str/ft_strcmp.c \
str/ft_strsplit.c \
str/ft_strncat.c \
str/ft_strcpy.c \
str/ft_strnstr.c \
str/ft_strstr.c \
mem/ft_realloc.c \
mem/ft_memset.c \
mem/ft_bzero.c \
mem/ft_memjoin.c \
mem/ft_memchr.c \
mem/ft_memcpy.c \
mem/ft_memcmp.c \
mem/ft_memccpy.c \
mem/ft_memmove.c \
mem/ft_memdel.c \
mem/ft_memalloc.c \
ctype/ft_isalnum.c \
ctype/ft_isalpha.c \
ctype/ft_tolower.c \
ctype/ft_toupper.c \
ctype/ft_isprint.c \
ctype/ft_isdigit.c \
ctype/ft_isascii.c \
ctype/ft_is_empty.c \
lists/ft_lstadd.c \
lists/ft_sorted_list_merge.c \
lists/ft_lst_find.c \
lists/ft_list_size.c \
lists/ft_list_last.c \
lists/ft_list_push_front.c \
lists/ft_lst_foreach.c \
lists/ft_sorted_list_insert.c \
lists/ft_lstiter.c \
lists/ft_list_push_back.c \
lists/ft_list_remove_if.c \
lists/ft_list_sort.c \
lists/ft_list_merge.c \
lists/ft_lstdel.c \
lists/ft_list_at.c \
lists/ft_lst_print.c \
lists/ft_lst_del_content.c \
lists/ft_lstmap.c \
lists/ft_lstnew.c \
lists/ft_lst_reverse.c \
lists/ft_lstdelone.c

SRCS	=	$(addprefix $(SRC_DIR), $(LIBFT_SRC))
OBJ := $(addprefix $(OBJ_DIR), $(LIBFT_SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "\033[0;32mlibft.a compiled\n\033[0m";

$(OBJ_DIR):
	@mkdir -p $@
	@mkdir -p $(dir $(OBJ))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@printf "\033[0;33m"
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR) -I$(FT_PRINTF_INC_DIR)

clean:
	@ if [ -e $(OBJ_DIR) ]; \
	then \
		$(RM) -r $(OBJ_DIR); \
		printf "\033[0;31m$(NAME) objects removed\n\033[0m"; \
	fi;

fclean: clean
	@ if [ -e $(NAME) ]; \
	then \
		$(RM) $(NAME); \
		printf "\033[0;31m$(NAME) removed\n\033[0m"; \
	fi;

re: fclean all

.PHONY: all clean fclean re
