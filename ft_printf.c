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

unsigned int	ft_print_string(char *str)
{
	unsigned int	size;

	size = ft_strlen(str);
	ft_putstr_fd(str, STDIN);
	return (size);
}

unsigned int	ft_print_number(int nbr)
{
	unsigned int	len;
	char	*str;

	str = NULL;
	len = 0;
	if (nbr < 0)
	{
		str = ft_itoa(nbr);
		len = ft_print_string(str);
		free(str);
	}
	else
	{
		ft_putnbr_fd(nbr, STDIN);
		while (nbr != 0)
		{
			len++;
			nbr /= 10;
		}
	}
	return (len);
}

unsigned int	ft_print_hexadecimal(unsigned int nbr, char type)
{
	if (type == 'x')
		return (ft_putnbr_base(nbr, "0123456789abcdef"));
	return (ft_putnbr_base(nbr, "0123456789ABCDEF"));
}

unsigned int	ft_print_arg(char c, va_list args)
{
	unsigned int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar_fd(va_arg(args, int), STDIN);
	else if (c == '%')
		len += ft_putchar_fd('%', STDIN);
	else if (c == 'd' || c == 'i')
		len += ft_print_number(va_arg(args, int));
	else if (c == 's')
		len += ft_print_string(va_arg(args, char *));
	else if (c == 'x' || c =='X')
		len += ft_print_hexadecimal(va_arg(args, unsigned int), c);
	else
		len += ft_print_pointer(va_arg(args, void *))
	return (len);
}

void	ft_treat_format(const char *format, va_list args, unsigned int *len)
{
	unsigned int	index;

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

unsigned int	ft_printf(const char *format, ...)
{
	va_list	args;
	unsigned int	len;

	len = 0;
	va_start(args, format);
	ft_treat_format(format, args, &len);
	va_end(args);
	return (len);
}
