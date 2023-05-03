# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 17:09:44 by jtorre-s          #+#    #+#              #
#    Updated: 2023/05/03 11:35:33 by jtorre-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = $(addprefix $(SRC_DIR)/, ${SRC:.c=.o})

NAME = push_swap

CC = gcc -Werror -Wall -Wextra

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = ./src

CFLAGS =  -Wall -Wextra -Werror

SRC = push_swap.c push_swap_utils.c checking.c movements.c exit.c init.c algoritm_2_3_5.c

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -L ./libft -l ft  -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

all : $(NAME)

clean:
		/bin/rm -f $(OBJ)
	
fclean: clean
		make -C $(LIBFT_DIR) fclean
		/bin/rm -f $(NAME)
		
re: fclean all

.PHONY: all clean fclean re