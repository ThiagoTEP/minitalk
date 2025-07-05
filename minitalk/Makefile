NAME_CLIENT = client
NAME_SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_CLIENT = client.c utils.c
SRCS_SERVER = server.c utils.c

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(SRCS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(SRCS_CLIENT)

$(NAME_SERVER): $(SRCS_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(SRCS_SERVER)

clean:
	rm -f

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re

