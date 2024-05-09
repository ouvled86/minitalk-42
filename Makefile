SERVER = server

CLIENT = client

SRV_SRCS = srcs/server.c

CLT_SRCS = srcs/client.c srcs/ft_atoi.c

PRF = ft_printf/ft_printf.o

SRV_OBJS = $(SRV_SRCS:.c=.o)

CLT_OBJS = $(CLT_SRCS:.c=.o)

HEADER = includes/minitalk.h

CFLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

$(SERVER): $(SRV_OBJS)
	@echo "Compiling server sources..."
	@cc $(CFLAGS) $(SRV_OBJS) $(PRF) -o $(SERVER)

$(CLIENT): $(CLT_OBJS)
	@echo "Compiling client sources..."
	@cc $(CFLAGS) $(CLT_OBJS) -o $(CLIENT)

bonus:


%.o: %.c $(HEADER) $(SRV_SRCS) $(CLT_SRCS)
	@cc -c (CFLAGS) $< -o $@

clean:
	@echo "Cleaning object files..."
	@rm -f $(SRV_OBJS) $(CLT_OBJS)

fclean:
	@echo "Cleaning object files and executables..."
	@rm -f $(SERVER) $(CLIENT) $(SRV_OBJS) $(CLT_OBJS)

re: fclean all