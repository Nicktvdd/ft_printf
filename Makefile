NAME = libftprintf.a
CC = cc -c
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = ft_printf.h
SRCFILES = ft_printf.c
OBJFILES = $(SRCFILES:%.c=%.o)


all: $(NAME)

$(NAME): $(OBJFILES)
	make -C libft
	cp libft/libft.a .
	mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJFILES)

$(OBJFILES): $(SRCFILES)
	$(CC) $(CFLAGS) $(SRCFILES) -I $(LDFLAGS)

.PHONY: clean

clean:
	rm -rf $(OBJFILES)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

test:
	make re
	cc test.c $(NAME)
	./a.out