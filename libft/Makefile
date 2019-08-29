# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skythoma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 17:43:03 by skythoma          #+#    #+#              #
#    Updated: 2019/03/05 20:23:37 by skythoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS += *.c	

NAME := libft.a

OBJ += *.o

.PHONY:
	clean fclean re

all: $(NAME)

$(NAME): $(SRCS)
	gcc -Wall -Wextra -Werror -I includes -c $(SRCS)
	ar rc $(NAME) $(OBJ)

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
