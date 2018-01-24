# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 14:29:23 by tmaraval          #+#    #+#              #
#    Updated: 2018/01/05 10:44:11 by tmaraval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = 	ft_conv.c \
		ft_list_dir.c \
		ft_parser.c \
		ft_check.c \
		ft_check_long.c \
		ft_lst.c \
		ft_print.c \
		ft_sort.c \
		ft_free.c \
		ft_utils.c \
		ft_fill.c \
		ft_print_simple.c \
		ft_main.c \
		ft_lst_utils.c \
		ft_parser_utils.c \
		ft_print_utils.c

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[92mCompilation de ft_ls...\033[0m"
	@(cd libft ; make; make clean)
	@gcc -Wall -Werror -Wextra -g $(OBJ) libft/libft.a -o $(NAME)
./%.o: %.c
	@gcc -Wall -Wextra -Werror -g -c $< -o $@

clean:
	@echo "\033[92mClean des .o...\033[0m"
	/bin/rm -f $(OBJ)
	@(cd libft ; make clean)

fclean: clean
	@echo "\033[92mFclean...\033[0m"
	/bin/rm -f $(NAME)
	/bin/rm -f libft/libft.a

re: fclean all

.PHONY: all clean fclean re
