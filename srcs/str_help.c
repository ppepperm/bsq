/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:43:40 by ppepperm          #+#    #+#             */
/*   Updated: 2019/08/21 13:15:16 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_func.h"

int		ft_atoi(char *str)
{
	int mult;
	int nb;

	mult = 1;
	nb = 0;
	while ((*str == ' ') || (*str == '\t'))
		str++;
	if (*str == '-')
	{
		str++;
		mult = -1;
	}
	if (*str == '+')
		str++;
	while (*str != '\0' && *(str + 3) != '\n')
	{
		if ((*str < '0') || (*str > '9'))
			return (nb * mult);
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return (nb * mult);
}

int		str_count_num(char *str)
{
	int i;

	i = 0;
	while (*str >= '0' && *str <= '9' && *(str + 3) != '\n')
	{
		str++;
		i++;
	}
	return (i);
}

int		false_print(void)
{
	write(2, "map error\n", 10);
	return (0);
}

int		ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (*str != '\n' || *str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}
