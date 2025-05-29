/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 07:54:03 by mda-enca          #+#    #+#             */
/*   Updated: 2025/04/30 07:54:09 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

int			ft_strlen_gnl(char *str);
char		*ft_strchr_gnl(const char *s, int c);
char		*ft_strjoin_gnl(char *s1, char *s2);
char		*get_next_line(int fd);
static char	*ft_extract_line(char *vault);
static char	*ft_remaining_line(char *vault);
static char	*ft_read_and_store(int fd, char *vault);

#endif
