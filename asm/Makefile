# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nharra <nharra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 18:13:07 by nharra            #+#    #+#              #
#    Updated: 2019/11/19 11:00:33 by nharra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FLAGS = -Wall -Werror -Wextra

SRCS =\
	asm.c\
	check_1.c\
	check_2.c\
	check_3.c\
	add_tokens.c\
	create_token.c\
	lex_analysis.c\
	skip.c\
	get_dir_size.c\
	syntax_analysis.c\
	lex_check_begin.c\
	op.c\
	read_file.c\
	check_op.c\
	init_labels.c\
	init_lab_op.c\
	create_byte_code.c\
	print_bytes.c\
	print_commands_byte.c\
	find_str.c\

OBJS = $(SRCS:.c=.o)

INCLUDE_DIR = ../includes

LIBFT_DIR = ../libft

NAME = asm

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
