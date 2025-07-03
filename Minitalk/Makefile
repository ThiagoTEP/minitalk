# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/23 11:30:18 by vmoura-d          #+#    #+#              #
#    Updated: 2025/05/26 09:44:04 by vmoura-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SRCS = server.c client.c utils_00.c utils_01.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): server client

server: server.c utils_00.c utils_01.c minitalk.h
	$(CC) $(CFLAGS) -o server server.c utils_00.c utils_01.c

client: client.c utils_00.c utils_01.c minitalk.h
	$(CC) $(CFLAGS) -o client client.c utils_00.c utils_01.c

clean:
	rm -f *.o

fclean: clean
	rm -f server client

re: fclean all

.PHONY: all clean fclean re
