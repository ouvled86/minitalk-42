NAME = libft.a

SRC =	ft_atoi.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c libft.h
	cc $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean