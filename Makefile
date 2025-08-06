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

NAME := libftprintf.a

SRCS := ft_printf.c ft_print_str.c ft_print_ptr.c ft_print_hex.c \
		ft_print_nbr.c ft_print_unbr.c 

OBJS := $(SRCS:%.c=%.o)

CFLAGS := -Wall -Wextra -Werror

LIBFTDIR := ./libft

LIBFT := $(LIBFTDIR)/libft.a

HEADERSFLAGS := -I. -I$(LIBFTDIR)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) 
	$(MAKE) -C $(LIBFTDIR)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	cc $(HEADERSFLAGS) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFTDIR)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFTDIR)/libft.a

re: fclean all

.PHONY: all clean fclean re
