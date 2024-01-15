/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:42:49 by momrane           #+#    #+#             */
/*   Updated: 2024/01/15 11:10:39 by momrane          ###   ########.fr       */
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
	if (*env == NULL)
		return ;
	if ((*env)->mlx != NULL)
	{
		if ((*env)->win != NULL)
			mlx_destroy_window((*env)->mlx, (*env)->win);
		mlx_destroy_display((*env)->mlx);
		free((*env)->mlx);
	}
	if ((*env)->lst != NULL)
		ft_free_points(&(*env)->lst);
	free(*env);
}
