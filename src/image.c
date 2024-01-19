/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:24:03 by momrane           #+#    #+#             */
/*   Updated: 2024/01/19 03:00:29 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_prep_img(t_env *env)
{
	env->img.img_ptr = mlx_new_image(env->mlx_ptr, env->width, env->height);
	if (!(env->img.img_ptr))
		ft_exit_error("mlx_new_image failed");
	env->img.img_data = mlx_get_data_addr(env->img.img_ptr, &env->img.bpp, &env->img.size_line, &env->img.endian);
	if (!(env->img.img_data))
		ft_exit_error("mlx_get_data_addr failed");
}
