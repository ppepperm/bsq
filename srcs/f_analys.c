/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_analys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:06:28 by ppepperm          #+#    #+#             */
/*   Updated: 2019/08/21 13:22:09 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_func.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int		line_len(int descr)
{
	int		count;
	char	c;

	c = 0;
	count = 0;
	while (c != '\n')
		count += read(descr, &c, 1);
	return (count);
}

char	*get_first_line(char *f_name)
{
	char	*tmp;
	int		len;
	int		descr;
	char	c;

	tmp = NULL;
	c = 0;
	descr = open(f_name, O_RDWR);
	if (descr > 0)
	{
		len = line_len(descr);
		close(descr);
		if (!(tmp = (char*)malloc(sizeof(char) * (len + 1))))
			return (0);
		descr = open(f_name, O_RDWR);
		len = read(descr, tmp, len);
		tmp[len] = '\0';
		if (!(valid_first_line(tmp)))
			return (NULL);
		close(descr);
	}
	return (tmp);
}

int		get_second_len(char *f_name)
{
	int len;
	int descr;

	len = -1;
	descr = open(f_name, O_RDWR);
	if (descr > 0)
	{
		len = line_len(descr);
		len = line_len(descr);
		close(descr);
	}
	return (len);
}

int		read_to_matr(t_matr dst, char *data_str, int descr)
{
	char	c;
	t_point	dot;

	c = 0;
	dot.i = 0;
	while (c != '\n')
		read(descr, &c, 1);
	while (read(descr, &c, 1))
	{
		dot.j = 0;
		while (c != '\n')
		{
			if (c == data_str[1])
				dst.matr[dot.i][dot.j] = 0;
			read(descr, &c, 1);
			dot.j++;
		}
		dot.i++;
	}
	return (1);
}
