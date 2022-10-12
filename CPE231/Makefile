# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponark <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 01:55:27 by tponark           #+#    #+#              #
#    Updated: 2022/10/12 13:34:22 by tponark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS = -r
CFLAGS = -Wall -Wextra -Werror
NAME = projlib.a
MAIN = main.c
SRCS = ft_merge_array.c ft_merge_sort.c ft_putarray.c ft_swap.c ft_hoare.c \
		ft_quick_sort_hoare.c ft_quick_sort_lomuto.c ft_lomuto.c ft_quick_select.c \

OBJS = $(SRCS:.c=.o)

all: $(MAIN)

%o: %c
	@echo "\033[93mCompiling $< to $@...\033[0m"
	@gcc -c $(CFLAGS) $< -o $@

$(MAIN): $(NAME)
	@echo "\033[93mCompiling output file from the library...\033[0m"
	@gcc $(CFLAGS) $@ $<

$(NAME): $(OBJS)
	@echo "\033[92mMaking .a from all the .o files...\033[0m"
	@ar -rcs $(NAME) $(OBJS)

clean:
	@echo "\033[91mCleaning objects...\033[0m"
	@rm -f $(OBJS)

fclean: clean
	@echo "\033[91mCleaning library...\033[0m"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
