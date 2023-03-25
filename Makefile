# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 17:09:44 by jtorre-s          #+#    #+#              #
#    Updated: 2023/03/24 14:41:18 by jtorre-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = $(SRC:.c=.o)

NAME = push_swap

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CFLAGS =  -Wall -Wextra -Werror

SRC = push_swap.c push_swap_utils.c checking.c

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