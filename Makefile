ASSEMBLER = asm
COREWAR = corewar
CC = gcc
FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
LIBFT = ./libft/libft.a
INCL = -I./includes/

ASM_SRC_FILES = assembler.c validate_file.c lexer.c token_validators.c \
hash_labels.c free_asm.c error_asm.c parse_utils.c tokenize.c \
is_arg.c token_to_statement.c token_to_arg.c translate_calculations.c \
write_bytecode.c

ASM_H = ./includes/assembler.h
ASM_SRC_DIR = ./srcs/asm/
ASM_SRC = $(addprefix $(ASM_SRC_DIR), $(ASM_ARC_FILES))
ASM_OBJ_DIR = ./srcs/objs/asm/
ASM_OBJ_FILES = $(ASM_SRC_FILES:.c=.o)
ASM_OBJ = $(addprefix $(ASM_OBJ_DIR), $(ASM_OBJ_FILES))


GAME =			checks.c \
				play.c

HELPERS =		init_carriages.c \
				print.c \
				print_2.c

MAIN =			main.c

PREREQUITES =	arena.c \
				champs.c \
				init.c \
				read_args.c \
				read_args_2.c \
				read_cor.c \
				read_cor_2.c

STATEMENTS =	op_add.c \
				op_aff.c \
				op_bitwise.c \
				op_fork.c \
				op_helpers.c \
				op_helpers_2.c \
				op_jump.c \
				op_load.c \
				op_load_index.c \
				op_live.c \
				op_store.c 

VISUALIZER =	arena.c



GAME_SRCS = $(addprefix srcs/vm/game/, $(GAME))
HELPERS_SRCS = $(addprefix srcs/vm/helpers/, $(HELPERS))
MAIN_SRCS = $(addprefix srcs/vm/main/, $(MAIN))
PREREQUITES_SRCS = $(addprefix srcs/vm/prerequites/, $(PREREQUITES))
STATEMENT_SRCS = $(addprefix srcs/vm/statements/, $(STATEMENTS))
VISUALIZER_SRCS = $(addprefix srcs/vm/visualizer/, $(VISUALIZER))

VM_SRC_FILES =	$(MAIN_SRCS) $(HELPERS_SRCS) \
				$(PREREQUITES_SRCS) $(VISUALIZER_SRCS) $(STATEMENT_SRCS) $(GAME_SRCS)

VM_OBJ_DIR = ./srcs/objs/vm/
VM_OBJ_FILES  = $(VM_SRC_FILES:.c=.o)


all: $(ASSEMBLER) $(COREWAR)
$(ASSEMBLER): $(ASM_OBJ) $(ASM_H) $(LIBFT) Makefile
	@$(CC) -o $@ $(FLAGS) $(INCL) $(ASM_OBJ) $(LIBFT)
	@echo "\033[0;33mAssembler compiled.\033[0m"

$(ASM_OBJ_DIR)%.o: $(ASM_SRC_DIR)%.c
	@mkdir -p $(ASM_OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@ $(INCL)

$(COREWAR): $(VM_OBJ_FILES) $(LIBFT)
	@$(CC) $(FLAGS) -o $@ $^
	@mkdir $(VM_OBJ_DIR)
	@mv $(VM_OBJ_FILES) $(VM_OBJ_DIR) 
	@echo "\033[0;33mVirtual machine compiled.\033[0m"

$(LIBFT):
	@$(MAKE) -C ./libft/
	@echo "\033[0;33mLibft compiled.\033[0m"

clean:
	@/bin/rm -rf ./srcs/objs
	@$(MAKE) -C ./libft/ clean
	@echo "\033[0;33mObjects folder removed.\033[0m"

fclean: clean
	@$(MAKE) -C ./libft/ fclean
	@rm -f $(ASSEMBLER)
	@rm -f $(COREWAR)
	@echo "\033[0;33mMake fclean done.\033[0m"

re: fclean all

vm: $(COREWAR)



.PHONY: all clean fclean re vm
