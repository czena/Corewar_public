# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nharra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 18:13:07 by nharra            #+#    #+#              #
#    Updated: 2019/11/20 17:08:14 by nharra           ###   ########.fr        #
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
	
SOURCES_DIR = srcs

SOURCE = $(addprefix $(SOURCES_DIR)/, $(SRCS))

OBJECTS_DIR = obj

OBJECTS = $(addprefix $(OBJECTS_DIR)/, $(OBJS))

OBJS = $(SRCS:.c=.o)

INCLUDE_DIR = ../includes

INCLUDES = asm.h \
			op.h \

INC = $(addprefix $(INCLUDE_DIR)/, $(INCLUDES))

NAME = ../asm

LIBFT = $(addprefix $(LIBFT_DIR)/, libft.a)

LIBFT_DIR = ../libft

LIBFT_INCLUDE_DIR = ../libft/includes

all: lib $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(OBJECTS_DIR) $(OBJECTS) $(INC)
	gcc -o $(NAME) $(OBJECTS)  -I $(LIBFT_INCLUDE_DIR) -I $(INCLUDE_DIR) -L ../libft/ -lft -lncurses $(FLAGS)

$(OBJECTS): | $(OBJECTS_DIR)

$(OBJECTS_DIR):
	mkdir $(OBJECTS_DIR)

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.c $(INC)
	gcc  -I$(INCLUDE_DIR) -I$(LIBFT_INCLUDE_DIR) -c $< -o $@ $(FLAGS)

lib:
	make -C $(LIBFT_DIR) all

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJECTS_DIR)

re: fclean all

.PHONY: all, clean, fclean, re, make_lib
