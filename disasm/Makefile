# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nharra <nharra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 18:13:07 by nharra            #+#    #+#              #
#    Updated: 2019/11/19 11:21:56 by nharra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FLAGS = -Wall -Werror -Wextra

SRCS =\
	create_token.c\
	create_tokens.c\
	disasm.c\
	get_dir_size.c\
	op.c\
	print.c\
	read_arg.c\

OBJS = $(SRCS:.c=.o)

INCLUDE_DIR = ../includes

LIBFT_DIR = ../libft

NAME = disasm

LIBFT = $(addprefix $(LIBFT_DIR)/, libft.a)

LIBFT_INCLUDE_DIR = ../libft/includes

all: $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(OBJS)
	gcc -o $(NAME) $(OBJS)  -I $(LIBFT_INCLUDE_DIR) -I $(INCLUDE_DIR) -L ../libft/ -lft $(FLAGS)

%.o: %.c
	gcc  -I$(INCLUDE_DIR) -I$(LIBFT_INCLUDE_DIR) -c $< -o $@ $(FLAGS)

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR) all

fclean:
	make -C $(LIBFT_DIR) fclean
	rm -rf *.o
	rm -rf $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf *.o

re: fclean all

.PHONY: all, clean, fclean, re, make_lib
