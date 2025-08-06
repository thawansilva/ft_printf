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
LIBFTDIR := libft
HEADERSFLAGS := -I. -I$(LIBFTDIR)
SRCS := ft_printf.c ft_print_str.c ft_print_ptr.c ft_print_hex.c \
		ft_print_nbr.c ft_print_unbr.c 

OBJS := $(SRCS:.c=.o)
LIBFT := $(LIBFTDIR)/libft.a
CFLAGS := -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) 
	$(MAKE) -C $(LIBFTDIR)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	cc $(CFLAGS) $(HEADERSFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFTDIR)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFTDIR)/libft.a

re: fclean all

.PHONY: all clean fclean re
