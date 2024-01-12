/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:57:32 by momrane           #+#    #+#             */
/*   Updated: 2023/11/27 13:38:03 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_string(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_print_string("(null)"));
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}
