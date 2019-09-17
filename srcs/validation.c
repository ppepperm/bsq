/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:00:13 by ppepperm          #+#    #+#             */
/*   Updated: 2019/09/06 12:48:10 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_func.h"
#include <unistd.h>
#include <fcntl.h>

int		valid_first_line(char *str)
{
	int		nbr;

	nbr = ft_atoi(str);
	str += str_count_num(str);
	if (*(str + 3) != '\n' || nbr <= 0)
		return (0);
	return (1);
}

int		smert(int descr, char *allowed_s, int len, int nbr_strings)
{
	t_point dot;

	if (!(descr > 0))
		return (0);
	while (allowed_s[2] != '\n')
		read(descr, &(allowed_s[2]), 1);
	dot.i = 0;
	while (read(descr, &(allowed_s[2]), 1))
	{
		dot.j = 0;
		while (allowed_s[2] != '\n')
		{
			if (allowed_s[2] != allowed_s[0] && allowed_s[2] != allowed_s[1])
				return (0);
			read(descr, &(allowed_s[2]), 1);
			dot.j++;
		}
		if (dot.j != len - 1)
			return (0);
		dot.i++;
	}
	if (dot.i != nbr_strings)
		return (0);
	return (1);
}

int		valid_all_other(char *fname, char *data_str)
{
	int		nbr_strings;
	int		len;
	int		descr;
	char	allowed_s[3];

	len = 0;
	nbr_strings = ft_atoi(data_str);
	len = get_second_len(fname);
	allowed_s[0] = *(data_str + str_count_num(data_str));
	allowed_s[1] = *(data_str + str_count_num(data_str) + 1);
	allowed_s[2] = 0;
	descr = open(fname, O_RDWR);
	if (!(descr > 0))
		return (0);
	return (smert(descr, allowed_s, len, nbr_strings));
}
