/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:59:24 by thaperei          #+#    #+#             */
/*   Updated: 2025/07/12 15:59:24 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_atoi(const char *nbr)
{
	int	sign;
	int	result;
	int	count_sign;

	count_sign = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(*nbr))
		nbr++;
	while (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			sign *= -1;
		count_sign++;
		nbr++;
	}
	if (count_sign > 1)
		return (0);
	while (ft_isdigit(*nbr))
		result = result * 10 + (*nbr++ - '0');
	return (result * sign);
}
