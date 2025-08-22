/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:37:16 by thaperei          #+#    #+#             */
/*   Updated: 2025/08/01 14:37:16 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"
# define STDOUT 1

typedef unsigned long long	t_ptr;

unsigned int	ft_print_nbr(int nbr);
unsigned int	ft_print_str(char *str);
unsigned int	ft_print_unbr(unsigned int nbr);
unsigned int	ft_print_ptr(unsigned long long ptr);
unsigned int	ft_print_hex(unsigned int nbr, char type);
unsigned int	ft_printf(const char *format, ...);
#endif 
