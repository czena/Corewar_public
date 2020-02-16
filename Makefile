# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nharra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 17:09:20 by nharra            #+#    #+#              #
#    Updated: 2019/11/20 17:16:42 by nharra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_ASM = asm

NAME_DISASM = disasm

NAME_VM = corewar

VM_DIR = VM

ASM_DIR = asm_dir

DISASM_DIR = disasm_dir

all: $(NAME_ASM) $(NAME_DISASM) $(NAME_VM)

$(NAME_ASM): make_asm

$(NAME_VM) : make_VM

$(NAME_DISASM) : make_disasm

make_asm:
	make -C $(ASM_DIR)
	
make_VM:
	make -C $(VM_DIR)

make_disasm:
	make -C $(DISASM_DIR)

clean:
	make -C $(DISASM_DIR) clean
	make -C $(VM_DIR) clean
	make -C $(ASM_DIR) clean

fclean:
	make -C $(DISASM_DIR) fclean
	make -C $(VM_DIR) fclean
	make -C $(ASM_DIR) fclean

re: fclean all

.PHONY: all, clean, fclean, re, make_asm, make_VM, make_disasm
