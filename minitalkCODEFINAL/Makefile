# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thevaris <thevaris@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/07 09:52:43 by thevaris          #+#    #+#              #
#    Updated: 2025/07/07 10:03:25 by thevaris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS_BONUS = client.c server.c

all: $(LIBFT) $(NAME_CLIENT) $(NAME_SERVER)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME_CLIENT): client.c minitalk.h
	$(CC) $(CFLAGS) client.c $(LIBFT) -o $(NAME_CLIENT)

$(NAME_SERVER): server.c minitalk.h
	$(CC) $(CFLAGS) server.c $(LIBFT) -o $(NAME_SERVER)

clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

bonus: all

.PHONY: all clean fclean re