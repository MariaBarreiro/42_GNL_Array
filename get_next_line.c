/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 08:26:27 by mda-enca          #+#    #+#             */
/*   Updated: 2025/05/02 17:09:39 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	ft_remaining(char *vault);
char	*ft_extract_line(char *vault, char *line);
char	*ft_read_and_store(int fd, char *line, char *vault);

char *get_next_line(int fd)
{
	static char	vault[BUFFER_SIZE + 1];
	char				*line;

	line = NULL;
	///check if fd is a valid value
	if (fd < 0)
		return (NULL);
	///check is vault is not empty and if it already contains a \n
	if (vault[0] && ft_strchr_gnl(vault, '\n'))
		return (ft_extract_line(vault, line));
	if (vault[0])
	{
		line = ft_strjoin_gnl(line, vault);
		if (!line)
			return (NULL);
	}
	line = ft_read_and_store(fd, line, vault);
	if (!line)
		return (NULL);
	line = ft_extract_line(vault, line);
	if (!line)
		return (NULL);
	return (line);
}

void	ft_remaining(char *vault)
{
	size_t	i;
	size_t	rest_i;

	i = 0;
	rest_i = 0;
	while (vault[i] && vault[i] != '\n')
		i++;
	///check if there's still content to read
	// if (!vault[i])
	// 	free (vault);
	i += 1; ///jump \n
	///rewrite in vault the remaining
	while (vault[i])
		vault[rest_i++] = vault[i++];
	///"delete" everything in front
	while (rest_i < BUFFER_SIZE)
		vault[rest_i++] = '\0';	
}

char	*ft_extract_line(char *vault, char *line)
{
	size_t	i;

	i = 0;
	if (!line)
	{
		line = (char *)malloc(sizeof (char) * 1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	///append to the line
	line = ft_strjoin_gnl(line, vault);
	while(line[i] != '\n' && line[i])
		i++;
	i += 1;
	line[i] = '\0';
	ft_remaining (vault);
	return (line);
}

char	*ft_read_and_store(int fd, char *line, char *vault)
{
	char	*new_line;
	int		bytes_read;

	new_line = line;
	ft_remaining(vault);
	while (1)
	{
		///reads up BUFFER_SIZE to vault
		bytes_read = read(fd, vault, BUFFER_SIZE);
		///error handling
		if (bytes_read < 0)
		{
			if (line)
				free(line);
			///restore the vault
			ft_remaining(vault);
			///bail out with NULL
			return (NULL);
		}
		///EOF check
		if (bytes_read == 0)
			break ;
		///append to the accumulator
		new_line = ft_strjoin_gnl(new_line, vault);
		///check if allocation fails
		if(!new_line)
			return (NULL);
		///stop on newline
		if (ft_strchr_gnl(vault, '\n'))
			break ;
		///prepare for the next iteration
		ft_remaining(vault);
	}
	return (new_line);
}
