ASSEMBLER = asm
COREWAR = corewar
CC = gcc
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LIBFT = ./libft/libft.a
INCL = -I./includes/
OBJS = ./srcs/objs

ASM_SRC_FILES = assembler.c validate_file.c lexer.c token_validators.c \
hash_labels.c free_asm.c error_asm.c parse_utils.c tokenize.c \
is_arg.c token_to_statement.c token_to_arg.c translate_calculations.c \
write_bytecode.c

ASM_H = ./includes/assembler.h
ASM_SRC_DIR = ./srcs/asm/
# ASM_SRC = $(addprefix $(ASM_SRC_DIR), $(ASM_SRC_FILES))
ASM_OBJ_DIR = ./srcs/objs/asm/
ASM_OBJ_FILES = $(ASM_SRC_FILES:.c=.o)
ASM_OBJ = $(addprefix $(ASM_OBJ_DIR), $(ASM_OBJ_FILES))



VM_SRC_FILES = checks.c play.c init_carriages.c print.c print_2.c main.c \
arena.c champs.c init.c read_args.c read_cor.c read_cor_2.c op_add.c op_aff.c \
op_bitwise.c op_fork.c op_helpers.c op_helpers_2.c op_jump.c op_load.c \
op_load_index.c op_live.c op_store.c

VM_H = ./includes/vm.h
VM_SRC_DIR = ./srcs/vm/
# VM_SRC = $(addprefix $(VM_SRC_DIR), $(VM_SRC_FILES))
VM_OBJ_DIR = ./srcs/objs/vm/
VM_OBJ_FILES = $(VM_SRC_FILES:.c=.o)
VM_OBJ = $(addprefix $(VM_OBJ_DIR), $(VM_OBJ_FILES))
# $(addprefix $(VM_OBJ_DIR)

all: $(ASSEMBLER) $(COREWAR)
# Add Makefile as prerequisite for $(Corewar), change syntax which would compile with Makefile
$(ASSEMBLER): $(ASM_OBJ) $(ASM_H) $(LIBFT) Makefile
	@$(CC) -o $@ $(FLAGS) $(INCL) $(ASM_OBJ) $(LIBFT)
	@echo "\033[0;33mAssembler compiled.\033[0m"

$(ASM_OBJ_DIR)%.o: $(ASM_SRC_DIR)%.c
	@mkdir -p $(ASM_OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@ $(INCL)


$(COREWAR): $(VM_OBJ) $(VM_H) $(LIBFT) Makefile
		@$(CC) $(FLAGS) -o $@ $(INCL) $(VM_OBJ) $(LIBFT)
		@echo "\033[0;33mVirtual machine compiled.\033[0m"

$(VM_OBJ_DIR)%.o: $(VM_SRC_DIR)%.c
	@mkdir -p $(VM_OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@ $(INCL)

$(LIBFT):
	@$(MAKE) -C ./libft/
	@echo "\033[0;33mLibft compiled.\033[0m"

clean:
	@/bin/rm -rf $(OBJS)
	@$(MAKE) -C ./libft/ clean
# Is following line with wildcats ok?
#		@mv srcs/vm/*/*.o $(VM_OBJ_DIR)
	@echo "\033[0;33mObjects folder deleted.\033[0m"

fclean: clean
	@$(MAKE) -C ./libft/ fclean
	@/bin/rm -f $(ASSEMBLER)
	@/bin/rm -f $(COREWAR)
	@echo "\033[0;33mMake fclean done.\033[0m"

re: fclean all

# Can remove before submit, not yet
vm: $(COREWAR)
	
vm_clean:
	@rm srcs/vm/*/*.o
# * * * * 


.PHONY: all clean fclean re
