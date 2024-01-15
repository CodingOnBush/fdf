/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:17:51 by momrane           #+#    #+#             */
/*   Updated: 2024/01/15 12:54:34 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

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
	int				row;
	int				col;
	int				width;
	int				height;
	struct s_point	*lst;
	struct s_img	*img;
}					t_env;

#endif