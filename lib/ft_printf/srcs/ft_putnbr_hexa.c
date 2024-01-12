/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:08:11 by momrane           #+#    #+#             */
/*   Updated: 2023/11/27 13:37:28 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr_hexa(unsigned long nbr, char format)
{
	int		out;
	char	*base;

	out = 0;
	if (nbr == (unsigned long)LONG_MIN)
		return (ft_print_string("8000000000000000"));
	else if (nbr == ULONG_MAX && format == 'X')
		return (ft_print_string("FFFFFFFFFFFFFFFF"));
	else if (nbr == ULONG_MAX && format == 'x')
		return (ft_print_string("ffffffffffffffff"));
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr >= 16)
		out += ft_putnbr_hexa(nbr / 16, format);
	out += ft_putchar(base[nbr % 16]);
	return (out);
}
