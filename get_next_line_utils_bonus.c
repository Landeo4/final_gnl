/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:44:03 by tpotilli          #+#    #+#             */
/*   Updated: 2023/02/10 10:44:05 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		len;

	if (!s1 && !s2)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	if (len == 0)
		return (NULL);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	len = -1;
	while (++len < ft_strlen(s1))
		str[len] = s1[len];
	while (len < ft_strlen(s2) + ft_strlen(s1))
	{
		str[len] = s2[i];
		i++;
		len++;
	}
	str[len] = '\0';
	return (str);
}

char	*free_join(char *backup, char *buffer)
{
	char	*stash;

	stash = ft_strjoin(backup, buffer);
	free(backup);
	return (stash);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*str;

	if (len < 0)
	{
		str = NULL;
		return (str);
	}
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len && (start + i) < ft_strlen(s))
		str[i] = s[start + i];
	str[i] = '\0';
	return (str);
}
