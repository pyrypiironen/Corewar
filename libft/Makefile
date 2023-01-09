NAME = libft.a
HEADER = libft.h
FLAGS = -Wall -Wextra -Werror

FILES = ft_atoi.c \
		ft_bzero.c \
		ft_countwords.c \
		ft_freearray.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_iswhitespace.c \
		ft_itoa.c \
		ft_itoa_base.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_wordlen.c \
		get_next_line.c

LIST_FILES = ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c

MEM_FILES = ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c

PUT_FILES = ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_free.c \
		ft_putstr_fd.c

STR_FILES = ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strduprev.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strjoin_free.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c

PRINTF_FILES = colors.c \
		conversion.c \
		convert_binary.c \
		convert_char.c \
		convert_double.c \
		convert_hexadecimal.c \
		convert_int.c \
		convert_modulo.c \
		convert_octal.c \
		convert_pointer.c \
		convert_string.c \
		convert_unsigned_int.c \
		dtoa.c \
		ft_printf.c \
		helpers_common.c \
		helpers_double.c \
		helpers_unsigned.c \
		print.c \
		read_specifiers.c \
		read_specifiers_2.c \
		struct_settings.c

LIST_SRCS = $(addprefix list/, $(LIST_FILES))
MEM_SRCS = $(addprefix mem/, $(MEM_FILES))
PUT_SRCS = $(addprefix put/, $(PUT_FILES))
STR_SRCS = $(addprefix str/, $(STR_FILES))
PRINTF_SRCS = $(addprefix ft_printf/srcs/, $(PRINTF_FILES))


SRCS = $(FILES) \
	$(LIST_SRCS) \
	$(MEM_SRCS) \
	$(PUT_SRCS) \
	$(STR_SRCS) \
	$(PRINTF_SRCS)

OBJS = $(FILES:.c=.o) \
	$(LIST_FILES:.c=.o) \
	$(MEM_FILES:.c=.o) \
	$(STR_FILES:.c=.o) \
	$(PUT_FILES:.c=.o) \
	$(PRINTF_FILES:.c=.o)
	

OBJS_DIR = objs/

.PHONY:	all	clean	fclean	re

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRCS) $(HEADER)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@mkdir $(OBJS_DIR)
	@mv *.o $(OBJS_DIR)
	@echo "Make succesfully done."

clean:
	@rm -rf $(OBJS_DIR)
	@echo "Make clean succesfully done."

fclean: clean
	@rm -f $(NAME) *.gch
	@echo "Make fclean succesfully done."

re: fclean all
