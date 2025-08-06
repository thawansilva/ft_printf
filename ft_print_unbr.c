/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:44:29 by thaperei          #+#    #+#             */
/*   Updated: 2025/08/06 10:44:29 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

unsigned int	ft_get_unbr_digits(unsigned int nbr)
{
	unsigned int	size;

	size = 0;
	while (nbr)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

void	ft_putunbr(unsigned int nbr)
{
	char	c;

	if (nbr >= 10)
	{
		ft_putunbr(nbr / 10);
		ft_putunbr(nbr % 10);
	}
	else
	{
		c = nbr + '0';
		write(STDIN, &c, 1);
	}
}
unsigned int	ft_print_unbr(unsigned int nbr)
{
	unsigned int	size;

	if (nbr == 0)
		return (write(STDIN, "0", 1));
	size = ft_get_unbr_digits(nbr);
	ft_putunbr(nbr);
	return (size);
}
