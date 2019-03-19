NAME := corewar

CC := gcc
CFLAGS = -Wall -Wextra -Werror -O3

SRC_DIR := sources/
INC_DIR := includes/
OBJ_DIR := obj/

LIBFT_DIR := libft/
LIBFT := $(LIBFT_DIR)/libft.a
LIBFT_INC := $(LIBFT_DIR)inc

LFT_FLAGS := -lft -L $(LIBFT_DIR)

SRC := \
main.c \
op/op.c \
op/op.h \
sources/check.c \
sources/commands/add.c \
sources/commands/aff.c \
sources/commands/and.c \
sources/commands/fork.c \
sources/commands/ld.c \
sources/commands/ldi.c \
sources/commands/lfork.c \
sources/commands/live.c \
sources/commands/lld.c \
sources/commands/lldi.c \
sources/commands/or.c \
sources/commands/st.c \
sources/commands/sti.c \
sources/commands/sub.c \
sources/commands/utils/op_args.c \
sources/commands/utils/op_argtypes.c \
sources/commands/utils/op_utils.c \
sources/commands/xor.c \
sources/commands/zjmp.c \
sources/corewar.c \
sources/corewar_args.c \
sources/corewar_options.c \
sources/debug.c \
sources/introduce.c \
sources/memory_free.c \
sources/player.c \
sources/process_list.c \
sources/terminate_vm.c \
sources/utils.c \
sources/validate_player.c \
sources/vm_cycle.c \
sources/winner.c

OBJ := $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

INC_FLAGS := -I$(INC_DIR) -I$(LIBFT_INC) -I$(LIBFT_INC)/ft_printf/

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	@printf "\033[0;33m"
	$(CC) $(OBJ) -o $(NAME) $(INC_FLAGS) $(LFT_FLAGS)
	@printf "\033[0;32m$(NAME) compiled\n\033[0m";

$(OBJ_DIR):
	@ mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@printf "\033[0;33m"
	$(CC) $(CFLAGS) -c $< -o $@ $(INC_FLAGS)
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@ if [ -e $(OBJ_DIR) ]; \
	then \
		$(RM) -r $(OBJ_DIR); \
		printf "\033[0;31m$(NAME) objects removed\n\033[0m"; \
	fi;
	@ $(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@ if [ -e $(NAME) ]; \
	then \
		$(RM) $(NAME); \
		printf "\033[0;31m$(NAME) removed\n\033[0m"; \
	fi;
	@ $(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
