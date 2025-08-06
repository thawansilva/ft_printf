/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:49:10 by thaperei          #+#    #+#             */
/*   Updated: 2025/08/04 10:49:10 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	ft_isvalid_base(char *base)
{
	size_t	size;
	size_t	i;
	size_t	j;

	if (!base)
		return (0);
	size = ft_strlen(base);
	if (size < 2)
		return (0);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (i + j < size)
		{
			if (base[i] == base[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_get_number_size(long nbr, size_t base_len)
{
	int	size;

	size = 0;
	if (nbr < 0)
	{
		size++;
		nbr *= -1;
	}
	while (nbr != 0)
	{
		size++;
		nbr /= base_len;
	}
	return (size);
}

static void	ft_print_reverse_arr(char *nbr, size_t size)
{
	while (size > 0)
		write(1, &nbr[size--], 1);
	write(1, &nbr[size], 1);
}

static void	ft_convert_nbr_to_base(long nbr, char *base)
{
	size_t	base_len;
	size_t	num_len;
	char	*number;
	int		sign;
	size_t	i;

	sign = (nbr >= 0) - (nbr < 0);
	base_len = ft_strlen(base);
	num_len = ft_get_number_size(nbr, base_len);
	number = calloc(num_len + 1, sizeof(char));
	if (!number)
		return ;
	i = 0;
	if (sign < 0)
		number[i++] = '-';
	while (i < num_len)
	{
		number[i++] = base[nbr % base_len];
		nbr /= base_len;
	}
	ft_print_reverse_arr(number, num_len);
	free(number);
}

void	ft_putnbr_base(unsigned int nbr, char *base)
{
	if (!ft_isvalid_base(base))
		return ;
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	ft_convert_nbr_to_base(nbr, base);
}
