# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2020/08/01 17:02:52 by ayzapata          #+#    #+#             #
#   Updated: 2020/08/13 17:37:22 by ayzapata         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME = libasm.a

DIR = ./srcs/

INCLUDE := -I./includes/

SRC := \
		ft_strlen.s \
    	ft_strcmp.s \
		ft_strcpy.s \
		ft_strdup.s \
		ft_write.s \
		ft_read.s 

SRCS_DIR = $(addprefix $(DIR), $(SRC))
OBJS = $(SRCS_DIR:.s=.o)
CC = clang

%.o: %.s
		nasm -felf64 $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

test:
		$(CC) ./tests/main.c $(NAME) -o asm


clean :
		rm -rf $(OBJS) asm

fclean : clean
		rm -rf $(NAME)

re : 	fclean all

.PHONY: re, clean, fclean, all