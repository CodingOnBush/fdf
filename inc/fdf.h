/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:27:51 by momrane           #+#    #+#             */
/*   Updated: 2024/01/15 13:54:56 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../lib/ft_printf/include/ft_printf.h"
# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include "get_next_line.h"
# include "struct.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_cross_hook(t_env *env);
int		ft_key_hook(int keycode, t_env *env);

void	ft_free_points(t_point **lst);
void	ft_free_everything(t_env *env);

void	ft_init_env(t_env **env, int ac, char **av);
void	ft_exit_error(char *str);

t_point	*ft_new_point(int x, int y, int z, int color);
void	ft_add_point(t_point **lst, t_point *new);

void	ft_init_hooks(t_env *env);

#endif