/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli@student42.fr  <tpotilli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:53:32 by tpotilli@st       #+#    #+#             */
/*   Updated: 2023/02/09 14:34:08 by tpotilli@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
char	*ft_first_backup(char *backup, int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_cpy(char *s1, char *s2, char *str);
char	*ft_str(char *backup);
int		ft_strlen(char *str);
char	*ft_clean(char *backup, int i);
char	*free_join(char *backup, char *buffer);
char	*ft_substr(char *s, int start, int len);
int		ft_find_newline(char *str);

#endif