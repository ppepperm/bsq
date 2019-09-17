/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matr_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:11:33 by ppepperm          #+#    #+#             */
/*   Updated: 2019/09/06 12:47:41 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_func.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void	init_matr(t_matr src)
{
	int i;
	int j;

	i = 0;
	while (i < src.n)
	{
		j = 0;
		while (j < src.m)
		{
			src.matr[i][j] = -1;
			j++;
		}
		i++;
	}
}

t_matr	create_matr(char *f_name)
{
	t_matr	tmp;
	int		i;
	char	*data_str;

	i = 0;
	data_str = get_first_line(f_name);
	tmp.n = ft_atoi(data_str);
	tmp.m = get_second_len(f_name) - 1;
	tmp.matr = (int**)malloc(sizeof(int*) * tmp.n);
	while (i < tmp.n)
	{
		tmp.matr[i] = (int*)malloc(sizeof(int) * tmp.m);
		i++;
	}
	init_matr(tmp);
	return (tmp);
}

t_matr	receive_matr(char *f_name)
{
	t_matr	tmp;
	int		descr;
	char	*data_str;

	tmp = create_matr(f_name);
	data_str = get_first_line(f_name);
	data_str += str_count_num(data_str);
	descr = open(f_name, O_RDWR);
	read_to_matr(tmp, data_str, descr);
	return (tmp);
}

int		min_of_three(int a, int b, int c)
{
	if (a > b)
		a = b;
	if (a > c)
		a = c;
	return (a);
}

void	solve(t_matr src)
{
	t_point dot;

	dot.i = 0;
	while (dot.i < src.n)
	{
		dot.j = 0;
		while (dot.j < src.m)
		{
			if (src.matr[dot.i][dot.j] != 0)
			{
				if (dot.i == 0 || dot.j == 0)
					src.matr[dot.i][dot.j] = 1;
				else
					src.matr[dot.i][dot.j] = min_of_three(\
							src.matr[dot.i - 1][dot.j]\
							, src.matr[dot.i][dot.j - 1]\
							, src.matr[dot.i - 1][dot.j - 1]) + 1;
			}
			dot.j++;
		}
		dot.i++;
	}
}
