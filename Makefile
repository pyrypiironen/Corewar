# Add header

ASSEMBLER = asm
COREWAR = corewar
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a



.PHONY: all

all: $(ASSEMBLER) $(COREWAR)

$(ASSEMBLER):



$(COREWAR):



$(LIBFT):
			@$(MAKE) -C libft

clean:

fclean:




re: fclean all

.PHONY: all clean fclean re
