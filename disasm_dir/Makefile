# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nharra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 18:13:07 by nharra            #+#    #+#              #
#    Updated: 2019/11/20 17:08:19 by nharra           ###   ########.fr        #
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

SOURCES_DIR = srcs

SOURCE = $(addprefix $(SOURCES_DIR)/, $(SRCS))

OBJECTS_DIR = obj

OBJECTS = $(addprefix $(OBJECTS_DIR)/, $(OBJS))

OBJS = $(SRCS:.c=.o)

INCLUDE_DIR = ../includes

INCLUDES = disasm.h \
			op.h \

INC = $(addprefix $(INCLUDE_DIR)/, $(INCLUDES))

NAME = ../disasm

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
