# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponark <tponark@student.42bangkok.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 18:25:19 by tponark           #+#    #+#              #
#    Updated: 2022/10/14 18:25:23 by tponark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS = -r
CFLAGS = -Wall -Wextra -Werror
NAME = projlib.a
MAIN = main.c
SRCS = merge_array.c merge_sort.c putarray.c swap.c hoare.c \
		quick_sort_hoare.c quick_sort_lomuto.c lomuto.c quick_select.c \

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
