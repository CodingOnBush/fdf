/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:17:51 by momrane           #+#    #+#             */
/*   Updated: 2024/01/20 17:42:55 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

typedef struct s_img
{
	void				*img_ptr;
	char				*img_data;
	int					bpp;
	int					endian;
	int					size_line;
}						t_img;

typedef struct s_pt
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_pt;

typedef struct s_parsing
{
	struct s_pt			**matrix;
	int					row;
	int					col;
	int					r;
	int					c;
	char				*filename;
}						t_parsing;

typedef struct s_env
{
	void				*mlx_ptr;
	void				*win_ptr;
	char				*address;
	char				*filename;
	int					width;
	int					height;
	float				angle;
	float				altitude;
	int					space;
	int					rows;
	int					cols;
	int					r;
	int					c;
	struct s_pt			origin;
	struct s_img		img;
	struct s_pt			**mat;
	struct s_pt			**map;
}						t_env;

#endif