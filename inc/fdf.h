/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:27:51 by momrane           #+#    #+#             */
/*   Updated: 2024/01/20 17:23:55 by momrane          ###   ########.fr       */
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

t_pt	**ft_new_matrix(int r, int c);

int	ft_count_cols(char *line);
int	ft_get_color(char *str);
int	ft_parse_map(t_env *env);

//			[free.c]
void		*ft_free_matrix(t_pt **matrix, int rows);
void		ft_free_env(t_env *env);
int			ft_free_env_err(t_env *env, char *msg);

int	ft_init_env(t_env *env, char *filename);
void	ft_init_env_values(t_env *env, char *filename);
void		ft_exit_error(char *str);

void		ft_trigger_hooks(t_env *env);

t_pt	ft_get_converted_point(t_env *env, int r, int c);
void	ft_set_space(t_env *env);

// t_parsing	ft_start_parsing(char *filename);

void	ft_draw(t_env *env);

void	ft_clear_img(t_env *env);

void		ft_transformation_points(t_env *env);

void		ft_init_img(t_env *env);

void		ft_move_points(t_env *env);

int	ft_get_new_x(t_env *env, int i, int j);
int	ft_get_new_y(t_env *env, int i, int j);
int	ft_get_new_z(t_env *env, int i, int j);

void	ft_print_point(t_env *env, int i, int j);
void	ft_parse_matrix(t_env *env, void (*f)(t_env *env, int i, int j));

#endif