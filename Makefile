ASSEMBLER = asm
COREWAR = corewar
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
INCL = -I./includes/

ASM_SRC_FILES = assembler.c validate_file.c lexer.c token_helpers.c \
init_asm.c hash_labels.c free_asm.c error_asm.c parse_utils.c tokenize.c \

ASM_H = ./includes/assembler.h
ASM_SRC_DIR = ./srcs/asm/
ASM_SRC = $(addprefix $(ASM_SRC_DIR), $(ASM_ARC_FILES))
ASM_OBJ_DIR = ./srcs/objs/asm/
ASM_OBJ_FILES = $(ASM_SRC_FILES:.c=.o)
ASM_OBJ = $(addprefix $(ASM_OBJ_DIR), $(ASM_OBJ_FILES))


MAIN =		main.c

CARRIAGES = init.c

PREREQUITES =	arena.c \
				champs.c \
				init.c \
				read_args.c \
				read_cor.c \
				read_cor_2.c

HELPERS =		error.c

#Delete when project is ready
TESTS =			prerequite_tests.c

STATEMENTS =	op_add.c \
				op_aff.c \
				op_fork.c \
				op_helpers.c \
				op_jump.c


MAIN_SRCS = $(addprefix srcs/vm/main/, $(MAIN))
CARRIAGES_SRCS = $(addprefix srcs/vm/carriages/, $(CARRIAGES))
PREREQUITES_SRCS = $(addprefix srcs/vm/prerequites/, $(PREREQUITES))
HELPERS_SRCS = $(addprefix srcs/vm/helpers/, $(HELPERS))
TESTS_SRCS = $(addprefix srcs/vm/tests/, $(TESTS))
STATEMENT_SRCS = $(addprefix srcs/vm/statements/, $(STATEMENTS))



VM_SRC_FILES =	$(MAIN_SRCS) $(CARRIAGES_SRCS) $(HELPERS_SRCS) \
				$(PREREQUITES_SRCS) $(TESTS_SRCS) $(STATEMENT_SRCS)

VM_OBJ_DIR = ./srcs/objs/vm/
VM_OBJ_FILES = $(VM_SRC_FILES:.c=.o)
VM_OBJ = $(VM_OBJ_FILES)
# $(addprefix $(VM_OBJ_DIR), 

all: $(ASSEMBLER) $(COREWAR)
# Add Makefile as prerequisite for $(Corewar), change syntax which would compile with Makefile
$(ASSEMBLER): $(LIBFT) $(ASM_OBJ) $(ASM_H) Makefile
	$(CC) -o $@ $(FLAGS) $(INCL) $(ASM_OBJ) $(LIBFT)
	@echo "Assembler done."

$(ASM_OBJ_DIR)%.o: $(ASM_SRC_DIR)%.c
	@mkdir -p $(ASM_OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@ $(INCL)

$(COREWAR): $(VM_OBJ) $(LIBFT)
		$(CC) $(FLAGS) -o $@ $^
		@echo "Virtual machine done."

# $(COREWAR): $(LIBFT) $(VM_OBJ) $(VM_H)
#	$(CC) -o $@ $(FLAGS) $(INCL) $(VM_SRC) $(LIBFT)

$(VM_OBJ_DIR)%.o: $(VM_SRC_DIR)%.c
	@mkdir -p $(VM_OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@ $(INCL)

$(LIBFT):
	@$(MAKE) -C ./libft/

clean:
	@/bin/rm -rf ./srcs/objs
	@$(MAKE) -C ./libft/ clean

fclean: clean
	@$(MAKE) -C ./libft/ fclean
	@/bin/rm $(ASSEMBLER)
	@/bin/rm $(COREWAR)

re: fclean all

vm: $(COREWAR)
	
vm_clean:
	@rm srcs/vm/*/*.o

.PHONY: all clean fclean re
