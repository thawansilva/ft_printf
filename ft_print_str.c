/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:33:54 by thaperei          #+#    #+#             */
/*   Updated: 2025/08/05 12:33:54 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_print_str(char *str)
{
	unsigned int	size;

	size = 0;
	if (!str)
		return (write(STDIN, "(null)", 6));
	size = ft_strlen(str);
	ft_putstr_fd(str, STDIN);
	return (size);
}
