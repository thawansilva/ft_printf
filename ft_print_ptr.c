/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:54:59 by thaperei          #+#    #+#             */
/*   Updated: 2025/08/05 12:54:59 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_get_ptr_digits(t_ptr ptr)
{
	unsigned int	size;

	size = 0;
	while (ptr != 0)
	{
		size++;
		ptr /= 16;
	}
	return (size);
}

static void	ft_putptr(t_ptr ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), STDIN);
		else
			ft_putchar_fd((ptr - 10 + 'a'), STDIN);
	}
}

unsigned int	ft_print_ptr(t_ptr ptr)
{
	unsigned int	size;

	size = 0;
	if (ptr == 0)
		size += write(STDIN, "(nil)", 5);
	else
	{
		size = write(STDIN, "0x", 2);
		ft_putptr(ptr);
		size += ft_get_ptr_digits(ptr);
	}
	return (size);
}
