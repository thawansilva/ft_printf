/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:25:21 by thaperei          #+#    #+#             */
/*   Updated: 2025/07/19 12:25:21 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	ft_getsize(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
	{
		size++;
		n = -n;
	}
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		size;
	long	num;
	char	*nbr;

	num = n;
	sign = 1;
	size = ft_getsize(num);
	nbr = (char *) malloc(size + 1);
	if (!nbr)
		return (0);
	nbr[size] = '\0';
	if (num < 0)
	{
		sign = -1;
		num = -num;
	}
	while (size--)
	{
		nbr[size] = num % 10 + '0';
		num /= 10;
	}
	if (sign < 0)
		nbr[0] = '-';
	return (nbr);
}
