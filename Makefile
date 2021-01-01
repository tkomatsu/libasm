# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/01 16:08:17 by tkomatsu          #+#    #+#              #
#    Updated: 2021/01/01 17:22:37 by tkomatsu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

AR = ar
ARFLAGS = -rc

AS = nasm
ASFLAGS = -f macho64

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/

FILES = ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s \
		ft_read.s \
		ft_strdup.s

SRCS = $(addprefix $(SRC_DIR), $(FILES))
OBJS = $(SRCS:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $<

.s.o:
	$(AS) $(ASFLAGS) -o $@ $<

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
