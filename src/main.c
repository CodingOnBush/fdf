/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:27:43 by momrane           #+#    #+#             */
/*   Updated: 2024/01/15 13:55:11 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int ac, char **av)
{
	t_env	*env;

	ft_init_env(&env, ac, av);
	ft_init_hooks(env);
	mlx_loop(env->mlx);
	return (0);
}
