/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:17:51 by momrane           #+#    #+#             */
/*   Updated: 2024/01/18 21:51:38 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

typedef struct s_img
{
	void			*img_ptr;
	char			*img_pixels_ptr;
	int				bits_per_pixel;
	int				endian;
	int				line_len;
}					t_img;

typedef struct s_pt
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_pt;

typedef struct s_parsing
{
	struct s_pt		**matrix;
	int				row;
	int				col;
	int				r;
	int				c;
	char			*filename;
}					t_parsing;

typedef struct s_env
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					width;
	int					height;
	int					x_offset;
	int					y_offset;
	int					z_offset;
	int					angle;
	int					zoom;
	int					scale;
	int					altitude;
	float				space;
	struct s_pt			origin;
	struct s_parsing	data;
	struct s_img		img;
}					t_env;

#endif