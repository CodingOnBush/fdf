/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:42:49 by momrane           #+#    #+#             */
/*   Updated: 2024/01/13 13:53:41 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_free_points(t_point **lst)
{
	t_point	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

void ft_free_env(t_env **env)
{
	t_point	*tmp;

	if (!env || !*env)
		return ;
	while ((*env)->lst)
	{
		tmp = (*env)->lst->next;
		free((*env)->lst);
		(*env)->lst = tmp;
	}
	free(*env);
}
