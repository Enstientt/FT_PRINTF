# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zessadqu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 16:18:19 by zessadqu          #+#    #+#              #
#    Updated: 2021/12/27 04:35:30 by zessadqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

HEADER = ft_printf.h

FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c spe.c ft_hexa.c ft_hexa_ptr.c

OBJCS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJCS)
	ar -rc $(NAME) $(OBJCS)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $<

clean :
	rm -f $(OBJCS)

fclean : clean
	rm -f $(NAME)

re : fclean all
