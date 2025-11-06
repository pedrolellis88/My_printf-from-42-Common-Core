# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdiniz-l <pdiniz-l@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 13:16:18 by pdiniz-l          #+#    #+#              #
#    Updated: 2025/11/06 10:40:58 by pdiniz-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = program

LIBFT = libftprintf.a

INCLUDE = ft_printf.h

MY_SOURCES = ft_printf.c \
	     chr_check.c \
	     ft_putchar.c \
	     ft_putstr.c \
	     ft_put_hex.c \
	     ft_put_void_pointer.c \
	     ft_putnbr.c \
	     ft_put_unsigned_nbr.c \
	     digits.c \
	     lower_or_upper.c  

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

.c.o: 
	cc $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	ar -rcs $(LIBFT) $(MY_OBJECTS)

clean: 
	rm -rf $(MY_OBJECTS) 

fclean: clean
	rm -rf $(LIBFT)

re: fclean all  


