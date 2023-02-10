/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli@student42.fr  <tpotilli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:51:30 by tpotilli@st       #+#    #+#             */
/*   Updated: 2023/01/27 11:41:09 by tpotilli@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd);

int main()
{
	int fd = 0;
	int i = 0;

	while (i < 3)
	{
		fd = open("/home/theo/Desktop/gnl_du_c/test.txt", O_WRONLY);
		printf("%s", get_next_line(fd));
		i++;
	}
	close (fd);
	return (0);
}
