/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:37:33 by thaperei          #+#    #+#             */
/*   Updated: 2025/08/05 12:37:33 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_puthex(char c)
{
	return (write(STDIN, &c, 1));
}

unsigned int	ft_print_hex(unsigned int nbr, char type)
{
	unsigned int	count;
	char			*base;

	count = 0;
	if (type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr < 16)
		count += ft_puthex(base[nbr]);
	else
	{
		count += ft_print_hex(nbr / 16, type);
		count += ft_print_hex(nbr % 16, type);
	}
	return (count);
}
