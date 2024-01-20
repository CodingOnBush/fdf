/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:09:12 by momrane           #+#    #+#             */
/*   Updated: 2024/01/20 18:17:21 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	ft_print_msg(t_env *env, t_pt p, char *msg)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr, p.x, p.y, 0x00FF0000, msg);
}

void	ft_draw_menu(t_env *env, t_pt p)
{
	ft_print_msg(env, p, "Move: AWSD");
	p.y += 20;
	ft_print_msg(env, p, "Zoom: mouse wheel");
	p.y += 20;
	ft_print_msg(env, p, "Rotate: arrows left/right");
	p.y += 20;
	ft_print_msg(env, p, "Altitude: arrows up/down");
	p.y += 20;
	ft_print_msg(env, p, "Exit: ESC");
	p.y += 20;
	ft_print_msg(env, p, "Reset: R");
	p.y += 20;
}
