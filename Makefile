# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/18 21:54:28 by ppepperm          #+#    #+#              #
#    Updated: 2019/08/21 11:31:07 by ppepperm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= bsq

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -o $(NAME) srcs/*.c -I headers

c:
	 gcc -Wall -Werror -Wextra -c srcs/*.c -I headers

clean:
	rm -f *.o
	rm -f buff_file

fclean: clean
	rm -f $(NAME)

re: fclean all
