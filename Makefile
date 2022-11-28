CC = cc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = libft.h
SRCFILES = 
NAME = ft_printf.a

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCFILES) -I $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all