/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 08:26:27 by mda-enca          #+#    #+#             */
/*   Updated: 2025/04/28 10:48:18 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

///fd: file descriptor to read from
///RETURN: SUCCESS: The next full line (with \n if present)  

char	*get_next_line(int fd)
{
	static char	*vault;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!vault)
	{
		vault = (char *)malloc(sizeof (char) * 1);
		vault[0] = '\0';
	}
	vault = ft_read_and_store(fd, vault);
	if (!vault)
		return (NULL);
	line = ft_extract_line(vault);
	vault = ft_remaining_line(vault);
	return (line);
}

static char *ft_remaining_line(char *vault)
{
	size_t	i;
	size_t	rest_i;
	char	*remaining_line;

	i = 0;
	rest_i = 0;
	///checkar se o vault tem algo
	if (!vault[i])
	{
		free (vault);
		return (NULL);
	}
	///procurar pelo resto da len no vault dps da extracted line
	while (vault[i] && vault[i] != '\n')
		i++;
	///alocar memoria para o resto
	remaining_line = (char *)malloc(sizeof (char) * (ft_strlen_gnl(vault) - i + 1));
	if (!remaining_line)
	{
		free (remaining_line);
		return (NULL);
	}
	///saltar a nova linha
	i += 1;
	///copiar o o que esta no vault a partir do index i para a remaining line
	while (vault[i])
		remaining_line[rest_i++] = vault[i++];
	remaining_line[rest_i] = '\0';
	free(vault);
	return (remaining_line);
}

static char *ft_extract_line(char *vault)
{
	size_t	i;
	char	*extracted_line;

	i = 0;
	if (!vault[i])
		return (NULL);
	///procurar pela nova linha para saber len
	while (vault[i] && vault[i] != '\n')
		i++;
	if (vault[i] == '\n') ///contar com a nova linha
		i += 1;
	///alocar memoria para a linha a ser extraida
	extracted_line = (char *)malloc(sizeof(char) * (i + 1));
	if (!extracted_line)
		return (NULL);
	///copy str para extracted_line
	i = -1;
	while (vault[++i] && vault[i] != '\n')
		extracted_line[i] = vault[i];
	if (vault[++i] == '\n')
		extracted_line[i] = vault[i];
	extracted_line[i]= '\0';
	return (extracted_line);
}

///ler ate buffer_size bytes from fd e armazenar em vault
///fd - file descriptor
///vault - pointer to the storage vault
///retorno - pointer para o vault ja preenchido com oq leu

static char	*ft_read_and_store(int fd, char *vault)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	///enquanto for diferente do \n E bytes_read != 0
	while (!ft_strchr_gnl(vault, '\n') && bytes_read != 0)
	{
		/// armazenar nos bytes read o valor que o programa  (read) leia(fd) e armazene no buffer ate ao BUFFER_SIZE
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		///se bytes_Read der erro (aka -1)
		if (bytes_read == -1)
		{
			///dar free ao buffer, ao vault , da o valor de NULL ao vault e retorna NULL
			free(buffer);
			free(vault);
			vault = NULL;
			return (NULL);
		}
		/// null terminate o buffer[bytes_read]
		buffer[bytes_read] = '\0';
		///copia para vault com o strjoin o que ficou no buffer
		vault = ft_strjoin_gnl(vault, buffer);
	}
	free(buffer);
	return (vault);
	///free ao buffer
	///retorna vault
}
