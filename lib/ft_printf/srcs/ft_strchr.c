/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:11:40 by momrane           #+#    #+#             */
/*   Updated: 2023/11/27 13:37:38 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	char			*ptr;
	unsigned char	val;

	if (!s)
		return (0);
	ptr = (char *)s;
	val = (unsigned char)c;
	while (*ptr != '\0')
	{
		if (*ptr == val)
			return (ptr);
		ptr++;
	}
	if (*ptr == val)
		return (ptr);
	return (0);
}
