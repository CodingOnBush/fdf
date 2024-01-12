/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:06:09 by momrane           #+#    #+#             */
/*   Updated: 2023/11/16 12:04:19 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*ptr;
	unsigned char	val;

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
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char s[] = "Hello, World!";
// 	char c = 'W';
// 	char *res = ft_strchr(s, c);

// 	printf("s: %s\n", s);
// 	if (res != NULL)
// 		printf("'%c' trouvé à la position : %ld\n", c, res - s);
// 	else
// 		printf("'%c' pas trouvé dans la chaîne\n", c);

// 	return (0);
// }
