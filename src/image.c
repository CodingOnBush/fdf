/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:24:03 by momrane           #+#    #+#             */
/*   Updated: 2024/01/18 11:24:31 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_prep_img(t_env *env)
{
	env->img.bits_per_pixel = 32;
	env->img.endian = 0;
	env->img.line_len = env->width * 4;
	env->img.img_ptr = mlx_new_image(env->mlx_ptr, env->width, env->height);
	if (!env->img.img_ptr)
		ft_exit_error("Error: mlx_new_image failed");
	env->img.img_pixels_ptr = mlx_get_data_addr(env->img.img_ptr,
			&env->img.bits_per_pixel, &env->img.line_len, &env->img.endian);
	if (!env->img.img_pixels_ptr)
	{
		mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
		ft_exit_error("Error: mlx_get_data_addr failed");
	}
}
