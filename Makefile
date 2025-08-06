# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thaperei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/06 09:00:05 by thaperei          #+#    #+#              #
#    Updated: 2025/08/06 09:00:05 by thaperei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFTDIR = libft
HEADER = -I. -I$(LIBFTDIR)
SRCS = ft_printf.c ft_print_str.c ft_print_ptr.c ft_print_hex.c \
		ft_print_nbr.c ft_print_unbr.c $(LIBFTDIR)/ft_strchr.c \
		$(LIBFTDIR)/ft_putchar_fd.c $(LIBFTDIR)/ft_itoa.c \
		$(LIBFTDIR)/ft_strlen.c $(LIBFTDIR)/ft_putstr_fd.c \

OBJS := $(SRCS:.c=.o)
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFTDIR)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	cc $(CFLAGS) $(HEADER) -c $< -o $@ 

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFTDIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFTDIR)/libft.a

re: fclean all

.PHONY: all clean fclean re
