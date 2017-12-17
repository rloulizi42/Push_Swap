# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/29 16:53:42 by rloulizi          #+#    #+#              #
#    Updated: 2017/12/05 17:11:30 by rloulizi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Iinclude -Wall -Wextra -Werror
CC = gcc
PATH_LIB=./Libft/libft.a
EXEC_PUSH = push_swap
EXEC_CHECK = checker

PATH_CHECK = src_checker/
PATH_PUSH = src_pushswap/

SRC1 = ft_create_elem.c ft_list_push_back.c ft_list_push_front.c op.c op2.c \
		get_next_line.c ft_check.c main.c ft_check_sort.c  median.c \
		quicksort.c insertion_sort.c sort_tab.c for_little.c op3.c \
		ft_check_main.c free_all.c \

SRC2 = ft_create_elem.c ft_list_push_back.c ft_list_push_front.c op.c op2.c \
		get_next_line.c ft_check.c main.c ft_check_sort.c op3.c free_all.c \


SRC_CHECKER = $(addprefix $(PATH_CHECK), $(SRC2))
SRC_PUSH = $(addprefix $(PATH_PUSH), $(SRC1))

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all: $(EXEC_PUSH) $(EXEC_CHECK)

$(EXEC_PUSH):
	@make -C ./Libft
	$(CC) -c $(FLAGS) $(SRC_PUSH)
	$(CC) $(OBJ1) $(PATH_LIB) -o $(EXEC_PUSH) 

$(EXEC_CHECK):
	@make -C ./Libft
	$(CC) -c $(FLAGS) $(SRC_CHECKER)
	$(CC) $(OBJ2) $(PATH_LIB) -o $(EXEC_CHECK)

%.o:%.c
	    gcc $(FLAGS) $< -o $@

clean:
	@make clean -C ./Libft
	/bin/rm -f $(OBJ2)
	/bin/rm -f $(OBJ1)

fclean: clean
	@make fclean -C ./Libft
	/bin/rm -f $(EXEC_CHECK)
	/bin/rm -f $(EXEC_PUSH)

re : fclean all

.PHONY : clean fclean re all
