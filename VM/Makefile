# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: czena <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 15:24:18 by czena             #+#    #+#              #
#    Updated: 2019/11/19 14:48:45 by czena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra -g

SRCS = corewar.c \
		parse_input.c \
		parse_flags.c \
		parse_file.c \
		parse_file2.c \
		print_errors.c \
		print_dump.c \
		arena_init.c \
		print_arena.c \
		players.c \
		param.c \
		cursor.c \
		cursor_create.c \
		start_battle.c \
		cursors_init.c \
		op.c \
		check_cursor_ready.c \
		operations.c \
		operations2.c \
		operations3.c \
		operations4.c \
		operations5.c \
		operations_cut.c \
		operations_functions.c \
		operations_functions2.c \
		check_types.c \
		print_players_winner_aff.c \
		print_borders.c \
		print_status.c \
		print_getch.c \
		print_players.c \

SOURCES_DIR = srcs

SOURCE = $(addprefix $(SOURCES_DIR)/, $(SRCS))

OBJECTS_DIR = obj

OBJECTS = $(addprefix $(OBJECTS_DIR)/, $(OBJS))

OBJS = $(SRCS:.c=.o)

INCLUDE_DIR = ../includes

INCLUDES = corewar.h\
			op.h \

NAME = corewar

LIBFT = $(addprefix $(LIBFT_DIR)/, libft.a)

LIBFT_DIR = ../libft

LIBFT_INCLUDE_DIR = ../libft/includes

all: lib $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(OBJECTS_DIR) $(OBJECTS)
	gcc -o $(NAME) $(OBJECTS)  -I $(LIBFT_INCLUDE_DIR) -I $(INCLUDE_DIR) -L ../libft/ -lft -lncurses $(FLAGS)

$(OBJECTS): | $(OBJECTS_DIR)

$(OBJECTS_DIR):
	mkdir $(OBJECTS_DIR)

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.c
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
