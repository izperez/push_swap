# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By izperez <izperez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 13:17:31 by izperez           #+#    #+#              #
#    Updated: 2024/02/22 13:43:03 by izperez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
INCLUDE = push_swap.h
CC = gcc
CFLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address
RM = rm -f

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

SRC = push_swap.c errors.c init_stack_a.c init_stack_b.c commands/push.c commands/swap.c
.SILENT:
all: $(NAME)

$(NAME): $(LIBFT) $(SRC) $(INCLUDE)
		$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
		@echo "\033[32mPUSH_SWAP COMPILED!\033[0m"

$(LIBFT):
		make -C $(LIBFT_DIR) all clean
		@echo "\033[33mLIBFT COMPILED!\033[0m"

clean: 
	make -C $(LIBFT_DIR) fclean

fclean: clean
		$(RM) $(NAME)

re: fclean all $(LIBFT)
