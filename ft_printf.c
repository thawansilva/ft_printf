/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:33:21 by thaperei          #+#    #+#             */
/*   Updated: 2025/08/01 14:33:21 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"
#include <stdio.h>

size_t	ft_print_string(char *str, int fd)
{
	size_t	size;

	size = ft_strlen(str);
	ft_putstr_fd(str, fd);
	return (size);
}

size_t	ft_print_number(int nbr, int fd)
{
	size_t	len;
	char	*str;

	str = NULL;
	len = 0;
	if (nbr < 0)
	{
		str = ft_itoa(nbr);
		len = ft_print_string(str, fd);
		free(str);
	}
	else
	{
		ft_putnbr_fd(nbr, fd);
		while (nbr != 0)
		{
			len++;
			nbr /= 10;
		}
	}
	return (len);
}

size_t	ft_print_arg(char c, va_list args)
{
	size_t	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar_fd(va_arg(args, int), STDIN);
	else if (c == '%')
		len += ft_putchar_fd('%', STDIN);
	else if (c == 'd' || c == 'i')
		len += ft_print_number(va_arg(args, int), STDIN);
	else if (c == 's')
		len += ft_print_string(va_arg(args, char *), STDIN);
//	else if (c == 'x' || c =='X')
//		len += ft_print_hexadecimal(va_arg(args, int), c, STDIN);
	return (len);
}

void	ft_treat_format(const char *format, va_list args, size_t *len)
{
	size_t	index;

	index = 0;
	while (format[index])
	{
		if (format[index] == '%' && ft_strchr("cspdiuxX%", format[index + 1]))
		{
			*len += ft_print_arg(format[index + 1], args);
			index += 2;
		}
		else
		{
			*len += ft_putchar_fd(format[index], STDIN);
			index++;
		}

	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	len;

	len = 0;
	va_start(args, format);
	ft_treat_format(format, args, &len);
	va_end(args);
	return (len);
}
