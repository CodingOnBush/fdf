/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:14:56 by momrane           #+#    #+#             */
/*   Updated: 2023/11/27 13:36:50 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_print_second_part(unsigned long ptr)
{
	int	out;

	out = 0;
	if (ptr == (unsigned long)LONG_MIN)
		return (ft_print_string("8000000000000000"));
	else if (ptr == ULONG_MAX)
		return (ft_print_string("ffffffffffffffff"));
	if (ptr >= 16)
		out += ft_print_second_part(ptr / 16);
	out += ft_putchar("0123456789abcdef"[ptr % 16]);
	return (out);
}

int	ft_print_ptr(void *ptr)
{
	int	out;

	out = 0;
	if (ptr == NULL)
		return (ft_print_string("(nil)"));
	if ((unsigned long)ptr == 0)
		return (ft_print_string("0x0"));
	out += ft_print_string("0x");
	out += ft_print_second_part((unsigned long)ptr);
	return (out);
}
