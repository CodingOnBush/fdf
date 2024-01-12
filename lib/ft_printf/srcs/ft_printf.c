/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:07:04 by momrane           #+#    #+#             */
/*   Updated: 2023/11/27 13:41:10 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_print_format(char format, va_list *args)
{
	if (format == '%')
		return (ft_putchar('%'));
	else if (format == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (ft_strchr("di", format))
		return (ft_print_integer(va_arg(*args, int)));
	else if (format == 's')
		return (ft_print_string(va_arg(*args, char *)));
	else if (ft_strchr("uxX", format))
		return (ft_print_uinteger(va_arg(*args, unsigned int), format));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(*args, void *)));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		out;
	int		i;

	va_start(args, s);
	out = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			out += ft_print_format(s[i + 1], &args);
			i += 2;
		}
		else
			out += ft_putchar(s[i++]);
	}
	va_end(args);
	return (out);
}

// #include <stdio.h>

// int main(void)
// {
// 	ft_printf("%d\n", 0);
// 	printf("%d\n", 0);
// 	ft_printf("%d\n", INT_MIN);
// 	printf("%d\n", INT_MIN);
// 	ft_printf("%s\n", "");
// 	printf("%s\n", "");
// 	ft_printf("%p\n", NULL);
// 	printf("%p\n", NULL);
// 	ft_printf("salut %d %s %p %d\n", 42, "salut", NULL, 0);
// 	printf("salut %d %s %p %d\n", 42, "salut", NULL, 0);
// 	return (0);
// }
