/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:19:11 by ppepperm          #+#    #+#             */
/*   Updated: 2019/08/21 15:14:25 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_func.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(t_matr src)
{
	t_point dot;

	dot.i = 0;
	while (dot.i < src.n)
	{
		dot.j = 0;
		while (dot.j < src.m)
		{
			ft_putchar(src.matr[dot.i][dot.j]);
			dot.j++;
		}
		ft_putchar('\n');
		dot.i++;
	}
}

int		do_the_thing(char *fname)
{
	t_matr	ban;
	char	*data_str;

	if (!(data_str = get_first_line(fname)))
		return (false_print());
	if (!(valid_all_other(fname, data_str)))
		return (false_print());
	data_str += str_count_num(data_str);
	ban = receive_matr(fname);
	solve(ban);
	paint_matr(ban, data_str);
	print(ban);
	free_matr(ban);
	return (1);
}

int		main(int ac, char **av)
{
	char	*fname;

	if (ac - 1)
	{
		av++;
		while (*av)
		{
			do_the_thing(*av);
			av++;
			if (*av)
				ft_putchar('\n');
		}
	}
	else
	{
		fname = save_raw_input();
		do_the_thing(fname);
	}
	return (0);
}
