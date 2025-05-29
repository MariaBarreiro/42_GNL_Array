/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 07:54:26 by mda-enca          #+#    #+#             */
/*   Updated: 2025/04/30 07:54:28 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

///Find a char in a given str;
///s: str to be searched;
///c: char to look for;
///return: pointer to the char found in str;

char	*ft_strchr_gnl(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == '\0' && (char)c == '\0')
		return ((char *)(s + i));
	return (0);
}

int	ft_strlen_gnl(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;
	char	*joined_str;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	len_s1 = ft_strlen_gnl(s1);
	len_s2 = ft_strlen_gnl(s2);
	joined_str = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!joined_str)
		return (NULL);
	while (i < len_s1)
		joined_str[j++] = s1[i++];
	i = 0;
	while (i < len_s2)
		joined_str[j++] = s2[i++];
	joined_str[j] = '\0';
	return (joined_str);
}
