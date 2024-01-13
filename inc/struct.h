/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:17:51 by momrane           #+#    #+#             */
/*   Updated: 2024/01/13 13:48:49 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_point	*next;
}					t_point;

typedef struct s_env
{
	void			*mlx;
	void			*win;
	char			*filename;
	struct s_point	*lst;
}					t_env;

#endif