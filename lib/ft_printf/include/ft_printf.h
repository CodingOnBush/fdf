/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:52:59 by momrane           #+#    #+#             */
/*   Updated: 2023/11/25 14:00:44 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>

int		ft_print_integer(int n);
int		ft_print_ptr(void *ptr);
int		ft_print_string(char *s);
int		ft_print_uinteger(unsigned int nb, char format);
int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_putnbr_hexa(unsigned long nbr, char format);
char	*ft_strchr(const char *s, int c);

#endif