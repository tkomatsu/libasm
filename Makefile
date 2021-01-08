# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/01 16:08:17 by tkomatsu          #+#    #+#              #
#    Updated: 2021/01/08 14:25:24 by tkomatsu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

AR = ar
ARFLAGS = -rc

AS = nasm
ASFLAGS = -f macho64

CC = gcc
CFLAGS = -Wall -Wextra -Werror

DEBUGFLAG = -g3

SRC_DIR = src/

FILES = ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s \
		ft_read.s
#		ft_strdup.s

SRCS = $(addprefix $(SRC_DIR), $(FILES))
OBJS = $(SRCS:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

clean:
	rm -rf $(OBJS) asm_test.dSYM *.log

fclean:
	rm -rf $(OBJS) $(NAME) asm_test asm_test.dSYM *.log

re: fclean all

debug: ASFLAGS += $(DEBUGFLAG)
debug: CFLAGS += $(DEBUGFLAG)
debug: fclean main

main: $(NAME)
	$(CC) $(CFLAGS) -o asm_test main.c $<

.PHONY: all clean fclean re 
