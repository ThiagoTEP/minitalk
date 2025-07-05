# **************************************************************************** #
#                              MINITALK PROJECT                                #
# **************************************************************************** #

# === Project ===
NAME_SERVER	= server
NAME_CLIENT	= client

# === Compiler ===
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# === Paths ===
SRCS_DIR	= .
LIBFT_DIR	= lib/libft
FT_PRINTF_DIR = $(LIBFT_DIR)/ft_printf
LIBFT		= $(LIBFT_DIR)/libft.a
FT_PRINTF	= $(FT_PRINTF_DIR)/libftprintf.a

# === Source Files ===
SRCS_SERVER	= server.c ft_sigaction.c ft_error.c ft_send.c ft_utils.c
SRCS_CLIENT	= client.c ft_sigaction.c ft_error.c ft_send.c ft_utils.c

# === Object Files ===
OBJS_SERVER	= $(SRCS_SERVER:.c=.o)
OBJS_CLIENT	= $(SRCS_CLIENT:.c=.o)

# === Rules ===

all: $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME_CLIENT)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
