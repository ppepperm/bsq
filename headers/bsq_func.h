/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_func.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:01:07 by ppepperm          #+#    #+#             */
/*   Updated: 2019/09/06 12:48:53 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_FUNC_H
# define BSQ_FUNC_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_point
{
	int i;
	int j;
}				t_point;

typedef struct	s_matr
{
	int **matr;
	int n;
	int m;
}				t_matr;

int				valid_first_line(char *str);
int				valid_all_other(char *fname, char *data_str);

int				ft_atoi(char *str);
int				str_count_num(char *str);
int				ft_strlen(char *str);
int				false_print(void);

int				line_len(int descr);
char			*get_first_line (char *f_name);
int				get_second_len(char *f_name);
t_matr			create_matr(char *f_name);
t_matr			receive_matr(char *f_name);
void			init_matr(t_matr src);
int				min_of_three(int a, int b, int c);
void			solve(t_matr src);
t_point			first_max(t_matr src);
void			prep_paint(t_matr src);
void			paint_matr(t_matr src, char *data_str);
int				read_to_matr(t_matr dst, char *data_str, int descr);
char			*save_raw_input(void);
void			free_matr(t_matr dst);

#endif
