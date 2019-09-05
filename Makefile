# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skythoma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/20 12:17:12 by skythoma          #+#    #+#              #
#    Updated: 2019/08/20 12:17:14 by skythoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c conversions.c printfuckery.c

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIBFT = ./libft/*.c

OBJS = *.o

all: $(NAME)

$(NAME):
	@echo "\033[32mCompiling source files\033[0m"
	@gcc $(FLAGS) -c $(SRCS) $(LIBFT)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@echo "\033[32mCleaning up\033[0m"
	@rm -f $(OBJS)

fclean: clean
	@echo "\033[32mFull clean\033[0m"
	@rm -rf $(NAME)

re: fclean all