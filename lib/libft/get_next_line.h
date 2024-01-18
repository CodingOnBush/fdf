/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:25:52 by adespond          #+#    #+#             */
/*   Updated: 2024/01/18 17:45:38 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# include <fcntl.h>

int		get_next_line(int const fd, char **line);

typedef struct		s_data
{
	char			*last;
	int				fd;
	struct s_data	*next;
	int				end;
}					t_data;

// int					get_next_line(int const fd, char **line);
#endif
