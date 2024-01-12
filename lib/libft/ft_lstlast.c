/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:17:30 by momrane           #+#    #+#             */
/*   Updated: 2023/11/16 07:54:56 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// #include <stdio.h>
// 
// int	main(void)
// {
// 	t_list *list = ft_lstnew("First");
//     ft_lstadd_back(&list, ft_lstnew("Second"));
//     ft_lstadd_back(&list, ft_lstnew("Third"));
// 
//     t_list *last = ft_lstlast(list);
//     if (last)
//         printf("last element: [%s|%p]\n", (char *)last->content, last->next);
// 	return (0);
// }