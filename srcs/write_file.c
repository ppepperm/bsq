/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:55:11 by ppepperm          #+#    #+#             */
/*   Updated: 2019/08/21 13:17:26 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

char	*save_raw_input(void)
{
	int		descr;
	char	*fname;
	char	c;

	fname = "buff_file";
	descr = open(fname, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	while (read(0, &c, 1))
		write(descr, &c, 1);
	close(descr);
	return (fname);
}
