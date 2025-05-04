/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:23:05 by mda-enca          #+#    #+#             */
/*   Updated: 2025/05/03 12:23:13 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(char *vault, char c)
{
	size_t	i;

	i = 0;
	if (!vault)
		return (NULL);
	/*GPT*/ 
	if (c == '\0')  // Return pointer to null terminator
	{
		while (vault[i])
			i++;
		return (&vault[i]);
	} /*GPT*/
	// if (c == '\0')
	// 	return (&vault[i]);
	// while (vault[i] != '\0')
	// {
	// 	if (vault[i] == c)
	// 		return (&vault[i]);
	// 	i++;
	// }
	return (0);
}

int	ft_strlen_gnl(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin_gnl(char *line, char *vault)
{
	size_t	i;
	size_t	j;
	size_t	len_vault;
	size_t	len_line;
	char	*joined_str;

	if (!line)
	{
		line = (char *)malloc(1 * sizeof(char));
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	if (!vault || !line)
		return (0);
	i = 0;
	j = 0;
	len_vault = ft_strlen_gnl(vault);
	len_line = ft_strlen_gnl(line);
	joined_str = (char *)malloc((len_vault + len_line + 1) * sizeof(char));
	if (!joined_str)
		return (NULL);
	while (i < len_line)
	{
		joined_str[i] = line[i];
		i++;
	}
	while (j < len_vault)
		joined_str[i++] = vault[j++];
	joined_str[i] = '\0';
	free(line);
	return (joined_str);
}
