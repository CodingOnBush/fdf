/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:36:17 by momrane           #+#    #+#             */
/*   Updated: 2023/11/27 13:37:09 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_integer(int n)
{
	long int	nb;
	int			out;

	nb = (long int)n;
	out = 0;
	if (nb < 0)
	{
		out += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		out += ft_print_integer(nb / 10);
		out += ft_putchar((nb % 10) + '0');
	}
	else
		out += ft_putchar(nb + '0');
	return (out);
}
