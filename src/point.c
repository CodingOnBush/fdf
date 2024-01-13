/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:17:47 by momrane           #+#    #+#             */
/*   Updated: 2024/01/13 12:39:02 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_point	*ft_new_point(int x, int y, int z, int color)
{
	t_point	*new;

	if (!(new = (t_point*)malloc(sizeof(t_point))))
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	new->color = color;
	new->next = NULL;
	return (new);
}

void	ft_add_point(t_point **lst, t_point *new)
{
	t_point	*tmp;

	tmp = *lst;
	if (!tmp)
		*lst = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
