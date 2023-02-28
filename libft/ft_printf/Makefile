NAME =  libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS = ./src/conversion.c\
	./src/conversion2.c\
	./src/flags.c\
	./src/insert_width.c\
	./src/itoa_base.c\
	./src/length.c\
	./src/lib1.c\
	./src/numbers.c\
	./src/as_parse.c\
	./src/parse.c\
	./src/strings.c\
	./src/ultoa_base.c\
	./src/utilities.c\
	./src/utilities2.c\
	./src/float.c\
	./src/rounding.c\
	./src/colour.c

OBJS = conversion.o conversion2.o flags.o insert_width.o itoa_base.o\
	length.o lib1.o numbers.o as_parse.o parse.o strings.o\
	ultoa_base.o utilities.o utilities2.o float.o rounding.o colour.o\
	ft_printf.o

INCL = -I ./includes

all: $(NAME)

$(NAME): $(SRCS)
	@gcc -O3 $(FLAGS) $(INCL) -c $(SRCS) ft_printf.c

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: clean fclean re all