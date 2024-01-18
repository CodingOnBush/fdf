/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:27:51 by momrane           #+#    #+#             */
/*   Updated: 2024/01/18 18:02:09 by momrane          ###   ########.fr       */
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
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

void		ft_free_everything(t_env *env);

t_env		ft_init_env(t_parsing data);
void		ft_exit_error(char *str);

void		ft_trigger_hooks(t_env *env);

t_parsing	ft_start_parsing(char *filename);

void	ft_draw(t_env *env);

void		ft_transformation_points(t_env *env);

void		ft_prep_img(t_env *env);

void		ft_move_points(t_env *env);

int	ft_get_new_x(t_env *env, int i, int j);
int	ft_get_new_y(t_env *env, int i, int j);
int	ft_get_new_z(t_env *env, int i, int j);

void	ft_print_point(t_env *env, int i, int j);
void	ft_parse_matrix(t_env *env, void (*f)(t_env *env, int i, int j));

#endif