/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uinteger.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:15:45 by momrane           #+#    #+#             */
/*   Updated: 2023/11/27 13:37:56 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_uinteger(unsigned int nb, char format)
{
	int				out;
	unsigned long	n;

	if (format == 'x' || format == 'X')
		return (ft_putnbr_hexa(nb, format));
	out = 0;
	n = (unsigned long)nb;
	if (n >= 10)
		out += ft_print_uinteger(n / 10, format);
	out += ft_putchar((n % 10) + '0');
	return (out);
}
