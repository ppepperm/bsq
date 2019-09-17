/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matr_lib2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 12:46:10 by ppepperm          #+#    #+#             */
/*   Updated: 2019/08/21 13:31:18 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_func.h"

t_point	first_max(t_matr src)
{
	t_point	dot;
	t_point	tmp;
	int		max;

	max = 0;
	dot.i = 0;
	while (dot.i < src.n)
	{
		dot.j = 0;
		while (dot.j < src.m)
		{
			if (src.matr[dot.i][dot.j] > max)
			{
				max = src.matr[dot.i][dot.j];
				tmp.i = dot.i;
				tmp.j = dot.j;
			}
			dot.j++;
		}
		dot.i++;
	}
	return (tmp);
}

void	prep_paint(t_matr src)
{
	t_point	max;
	t_point	dot;
	int		max_size;

	max = first_max(src);
	max_size = src.matr[max.i][max.j];
	dot.i = 0;
	while (dot.i < max_size)
	{
		dot.j = 0;
		while (dot.j < max_size)
		{
			src.matr[max.i - dot.i][max.j - dot.j] = -1;
			dot.j++;
		}
		dot.i++;
	}
}

void	paint_matr(t_matr src, char *data_str)
{
	t_point dot;

	dot.i = 0;
	prep_paint(src);
	while (dot.i < src.n)
	{
		dot.j = 0;
		while (dot.j < src.m)
		{
			if (src.matr[dot.i][dot.j] > 0)
				src.matr[dot.i][dot.j] = data_str[0];
			if (src.matr[dot.i][dot.j] == 0)
				src.matr[dot.i][dot.j] = data_str[1];
			if (src.matr[dot.i][dot.j] < 0)
				src.matr[dot.i][dot.j] = data_str[2];
			dot.j++;
		}
		dot.i++;
	}
}

void	free_matr(t_matr dst)
{
	int i;

	i = 0;
	while (i < dst.n)
	{
		free(dst.matr[i]);
		i++;
	}
	free(dst.matr);
}
