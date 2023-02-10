/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli@student42.fr  <tpotilli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:54:18 by tpotilli@st       #+#    #+#             */
/*   Updated: 2023/02/09 14:33:21 by tpotilli@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_first_backup(char *backup, int fd)
{
	int		help;
	char	*buffer;

	help = 1;
	while (!ft_strchr(backup, '\n') && help != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		help = read(fd, buffer, BUFFER_SIZE);
		if (help == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[help] = '\0';
		backup = free_join(backup, buffer);
		free(buffer);
	}
	return (backup);
}

char	*ft_get_str(char *backup)
{
	char	*new_line;

	if (!backup)
		return (NULL);
	if (ft_find_newline(backup) >= 0)
		new_line = ft_substr(backup, 0, ((ft_find_newline(backup) + 1)));
	else
		new_line = ft_substr(backup, 0, ft_strlen(backup));
	return (new_line);
}

int	ft_find_newline(char *str)
{
	int	i;

	i = -1;
	if (!(str))
		return (-1);
	while (str[++i])
	{
		if (str[i] == '\n')
			return (i);
	}
	return (-1);
}

char	*ft_next_line(char *backup)
{
	int		i;
	char	*new;

	i = (ft_strlen(backup) - ft_find_newline(backup));
	if (!backup || ft_find_newline(backup) == -1)
	{
		free(backup);
		return (NULL);
	}
	else
		new = ft_substr(backup, (ft_find_newline(backup) + 1), i);
	free(backup);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = ft_first_backup(backup, fd);
	if (!backup)
		return (NULL);
	str = ft_get_str(backup);
	backup = ft_next_line(backup);
	return (str);
}
