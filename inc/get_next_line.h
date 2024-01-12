/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:04:12 by momrane           #+#    #+#             */
/*   Updated: 2024/01/12 12:54:56 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_node
{
	char			*str;
	struct s_node	*next;
}					t_node;

char	*ft_gnl(int fd);
int		ft_createlst(int fd, t_node **lst);
void	ft_lstappend(t_node **lst, char *buff);
void	ft_update_lst(t_node **lst);
void	*ft_freelst(t_node **lst);
char	*ft_create_str(t_node *lst);
char	*ft_get_after_nl(char *str);
// char	*ft_strchr(char *s, char c);
int		ft_get_len(t_node *lst);
int		ft_lstchr(t_node *lst);

#endif
